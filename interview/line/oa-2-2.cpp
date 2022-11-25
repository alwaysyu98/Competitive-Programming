#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	ios:wsync_with_stdiq(false);
	cin.tie(0);
	cout.tie(0);

	// from "date and time" to "tm" type
	auto transTimeToTm = [&](string &s) {
		tm timestamp;
		timestamp.tm_min = stoi(s.substr(3));
		timestamp.tm_hour = stoi(s.substr(0, 2));
		return timestamp;
	};

	auto cmp_time = [&](tm tm1, tm tm2) {
		if (tm1.tm_mday < tm2.tm_mday) return 0;
		if (tm1.tm_mday > tm2.tm_mday) return 1;
		if (tm1.tm_hour < tm2.tm_hour) return 0;
		if (tm1.tm_hour > tm2.tm_hour) return 1;
		if (tm1.tm_min < tm2.tm_min) return 0;
		if (tm1.tm_min > tm2.tm_min) return 1;

		return 2;
	};

	auto cal_minutes = [&](int day, tm tm_time) {
		return day * 24 * 60 + tm_time.tm_hour * 60 + tm_time.tm_min;
	};

	// get restaurant information
	int n, k;
	string s;

	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> s >> k;

	vector<pair<tm, tm>> slots(k + 2);
	string s1 = s.substr(0, 5), s2 = s.substr(6);
	slots[k + 1].first = transTimeToTm(s1);
	slots[k + 1].second = transTimeToTm(s2);
	for (int i = 1; i <= k; ++i) {
		auto &[x, y] = slots[i];
		cin >> s;
		string s1 = s.substr(0, 5), s2 = s.substr(6);
		x = transTimeToTm(s1), y = transTimeToTm(s2);
	}

	//map[day][slot][tableid] -> record the reservation using index
	vector reservationMap(1001, vector (20, vector<string> (20)));
	// customerId -> reservation
	unordered_map<string, tuple<int, int, int, bool, int>> customerReservation;
	// set for unspecified table
	// set<pair<int, string>> unsepecifiedReservationSet;

	string queryStr;
	while (!cin.eof()) {
		vector<string> query;
		getline(cin, queryStr);

		// get query array
		string delim = " ";
		int start = 0, end = queryStr.find(delim, start);
		while (end != queryStr.npos) {
			query.push_back(queryStr.substr(start, end - start));
			start = end + delim.size();
			end = queryStr.find(delim, start);
		}
		query.push_back(queryStr.substr(start));

		// parse query
		if (query.size() == 4 && query[2] == "time") { // time query
			int day = stoi(query[0]), x = stoi(query[3]);
			string time = query[1];

			tm tm_time = transTimeToTm(time);

			// beginning of a slot
			if (2 <= x && cmp_time(tm_time, slots[x - 1].second) == 2) {
				for (int i = 1; i <= n; ++i) {
					reservationMap[day][x - 1][i] = "";
				}
			}
			// end of a slot
			if (x <= k) {
				for (int i = 1; i <= n; ++i) {
					if (reservationMap[day][x][i].size() != 0)
						cout << day << " " << time << " table " << i << " = " << reservationMap[day][x][i] << '\n';
				}
			}

		} else if (query.size() == 8) { // issue specified ticket query
			int day = stoi(query[0]), reservationDay = stoi(query[4]), slotIndex = stoi(query[5]), numberOfPeople = stoi(query[6]), tableId = stoi(query[7]);
			string time = query[1], customerId = query[3];

			tm currentTime = transTimeToTm(time);
			// condition 1
			if (day == reservationDay && cmp_time(currentTime, slots[slotIndex].first) && cmp_time(currentTime, slots[slotIndex].second) == 0) {
				cout << day << " " << time << " Error: the current slot cannot be specified.\n";
			} else if (day > reservationDay || (day == reservationDay && cmp_time(currentTime, slots[slotIndex].second))) { // condition 2 
				cout << day << " " << time << " Error: a past time cannot be specified.";
			} else if (numberOfPeople > a[tableId]) {// condition 3
				cout << day << " " << time << " Error: the maximum number of people at the table has been exceeded.";
			} else if (reservationMap[day][slotIndex][tableId].size() != 0) {
				cout << day << " " << time << " Error: the table is occupied.";
			} else {
				reservationMap[reservationDay][slotIndex][tableId] = customerId;
				customerReservation[customerId] = {reservationDay, slotIndex, tableId, true, numberOfPeople};
				cout << day << " " << time << " " << customerId << '\n';
			}
		} else if (query.size() == 7) {
			int day = stoi(query[0]), reservationDay = stoi(query[4]), slotIndex = stoi(query[5]), numberOfPeople = stoi(query[6]);
			string time = query[1], customerId = query[3];

			tm currentTime = transTimeToTm(time);
			if (day == reservationDay && cmp_time(currentTime, slots[slotIndex].first) && cmp_time(currentTime, slots[slotIndex].second) == 0) {
				cout << day << " " << time << " Error: the current slot cannot be specified.\n";
			} else if (day > reservationDay || (day == reservationDay && cmp_time(currentTime, slots[slotIndex].second))) { // condition 2 
				cout << day << " " << time << " Error: a past time cannot be specified.";
			} else {
				// specify a table 
				int tableId = -1;
				for (int i = 1; i <= n; ++i) {
					if (reservationMap[reservationDay][slotIndex][i].size() == 0 && a[i] >= numberOfPeople) {
						if (tableId == -1 || a[tableId] > a[i])
							tableId = i;
					}
				}

				if (tableId == -1) {
					cout << day << " " << time << " Error: no available table is found.\n";
				} else {
					reservationMap[reservationDay][slotIndex][tableId] = customerId;
					customerReservation[customerId] = {reservationDay, slotIndex, tableId, false, numberOfPeople};
					cout << day << " " << time << " " << customerId << " " << tableId << '\n';
				}
			}
		} else if (query.size() == 4 && query[2] == "cancel") {
			int day = stoi(query[0]);
			string time = query[1], customerId = query[3];

			tm currentTime = transTimeToTm(time);
			// condition 1
			if (customerReservation.count(customerId) == 0) {
				cout << day << " " << time << " Error: no such ticket is found.\n";
			} else {
				auto [resDay, resSlot, resTable, ok, numberOfPeople] = customerReservation[customerId];

				if (cal_minutes(resDay, slots[resSlot].first) - cal_minutes(day, currentTime) <= 24 * 60) {
					cout << day << " " << time << " Error: you must cancel at least 24 hours in advance.\n";
				} else {
					reservationMap[resDay][resSlot][resTable] = "";
					customerReservation.erase(customerId);

					// then we need to scan the existing unspecified tickets in descending order or the number of people
					vector<tuple<int, int, int, int>> tables;
					for (auto &[cid, tp] : customerReservation) {
						auto [td, ts, tt, tok, numberOfPeople] = tp;
						if (!tok && a[tt] >= a[resTable]) {
							tables.emplace_back(td, ts, tt, numberOfPeople);
						}
					}

					sort(tables.begin(), tables.end(), [&](const tuple<int, int, int, int> &t1, const tuple<int, int, int, int> &t2) {
							auto &[td1, ts1, tt1, n1] = t1;
							auto &[td2, ts2, tt2, n2] = t2;
							if (a[tt1] > a[tt2]) return true;
							else if (a[tt1] < a[tt2]) return false;
							return reservationMap[td1][ts1][tt1] < reservationMap[td2][ts2][tt2];
							});

					for (auto [td, ts, tt, numberOfPeople] : tables) {
						// specify a table 
						string customerId = reservationMap[td][ts][tt];
						customerReservation.erase(customerId);
						reservationMap[td][ts][tt] = "";

						int tableId = -1;
						for (int i = 1; i <= n; ++i) {
							if (reservationMap[td][ts][i].size() == 0 && a[i] >= numberOfPeople) {
								if (tableId == -1 || a[tableId] > a[i])
									tableId = i;
							}
						}

						reservationMap[td][ts][tableId] = customerId;
						customerReservation[customerId] = {td, ts, tt, false, numberOfPeople};
					}

					cout << day << " " << time << " Canceled " << customerId << "\n";
				}
			}
		}
	}
	return 0;
}

