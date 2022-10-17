#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int op;
	cin >> op;
	if (op == 1) {
		// stock quantatity hash map;
		unordered_map<int, pair<int, int>> idToStockQuantatityAndPriceMap;

		int m, d, s, p, t, n;
		string tmp;
		cin >> m;

		for (int i = 0; i < m; ++i) {
			cin >> d >> s >> p;
			idToStockQuantatityAndPriceMap[d] = {s, p};
		}

		while (cin >> tmp >> t >> d >> n) {
			int &leftQuantity = idToStockQuantatityAndPriceMap[d].first;
			// less than the quantity ordered
			if (leftQuantity < n) {
				cout << "sold out " << t << '\n';
			} else {
				leftQuantity -= n;
				for (int i = 0; i < n; ++i) {
					cout << "received order " << t << " " << d << '\n';
				}
			}
		}
	} else if (op == 2) {
		int m, k;
		cin >> m >> k;

		// stock quantatity hash map;
		unordered_map<int, pair<int, int>> idToStockQuantatityAndPriceMap;

		int d, s, p;
		for (int i = 0; i < m; ++i) {
			cin >> d >> s >> p;
			idToStockQuantatityAndPriceMap[d] = {s, p};
		}

		unordered_map<int, int> isMenuIDBeingCooked;
		// received order queue
		queue<int> q;

		string line;
		while (!cin.eof()) {
			getline(cin, line);

			size_t pos = 0;
			const string delimiter = " ";
			vector<string> tokens;

			while ((pos = line.find(delimiter)) != string::npos) {
				tokens.push_back(line.substr(0, pos));
				line.erase(0, pos + delimiter.size());
			}
			tokens.push_back(line);

			if (tokens.size() == 4) {
				int t = stoi(tokens[2]), d = stoi(tokens[3]);

				if (k <= 0) {
					cout << "wait\n";
					q.push(d);
				} else {
					k -= 1;
					isMenuIDBeingCooked[d] += 1;
					cout << d << '\n';
				}
			} else if (tokens.size() == 2) {
				int d = stoi(tokens[1]);

				if (isMenuIDBeingCooked[d] > 0) {
					k += 1;
					isMenuIDBeingCooked[d] -= 1;
					// if (isMenuIDBeingCooked.count(d) == 0) isMenuIDBeingCooked.erase(d);

					if (q.size()) {
						cout << "ok " << q.front() << '\n';
						isMenuIDBeingCooked[q.front()] += 1;
						q.pop();
						k -= 1;
					} else {
						cout << "ok\n";
					}
				} else {
					cout << "unexpected input\n";
				}
			}
		}
	} else if (op == 3) {
		int m;
		cin >> m;

		// stock quantatity hash map;
		unordered_map<int, pair<int, int>> idToStockQuantatityAndPriceMap;

		int d, s, p;
		for (int i = 0; i < m; ++i) {
			cin >> d >> s >> p;
			idToStockQuantatityAndPriceMap[d] = {s, p};
		}
		// order queue
		unordered_map<int, queue<int>> menuIdToTableId;

		string line;
		while (!cin.eof()) {
			getline(cin, line);

			size_t pos = 0;
			const string delimiter = " ";
			vector<string> tokens;

			while ((pos = line.find(delimiter)) != string::npos) {
				tokens.push_back(line.substr(0, pos));
				line.erase(0, pos + delimiter.size());
			}
			tokens.push_back(line);

			if (tokens.size() == 4) {
				int t = stoi(tokens[2]), d = stoi(tokens[3]);
				menuIdToTableId[d].push(t);
			} else if (tokens.size() == 2) {
				int d = stoi(tokens[1]);
				int t = menuIdToTableId[d].front();
				menuIdToTableId[d].pop();
				if (menuIdToTableId[d].size() == 0) {
					menuIdToTableId.erase(d);
				}

				cout << "ready " << t << " " << d << '\n';
			}
		}
	} else if (op == 4) {
		int m;
		cin >> m;

		// stock quantatity hash map;
		unordered_map<int, pair<int, int>> idToStockQuantatityAndPriceMap;

		// map for one table
		unordered_map<int, int> tableIdToMenuQuantityMap;
		unordered_map<int, int> tableIdToMenuCostMap;

		int d, s, p;
		for (int i = 0; i < m; ++i) {
			cin >> d >> s >> p;
			idToStockQuantatityAndPriceMap[d] = {s, p};
		}

		string line;
		while (!cin.eof()) {
			getline(cin, line);

			size_t pos = 0;
			const string delimiter = " ";
			vector<string> tokens;

			while ((pos = line.find(delimiter)) != string::npos) {
				tokens.push_back(line.substr(0, pos));
				line.erase(0, pos + delimiter.size());
			}
			tokens.push_back(line);

			if (tokens.size() == 4) {
				int t = stoi(tokens[2]), d = stoi(tokens[3]);
				tableIdToMenuQuantityMap[t] += 1;
				tableIdToMenuCostMap[t] += idToStockQuantatityAndPriceMap[d].second;
			} else if (tokens.size() == 3) {
				int t = stoi(tokens[1]), d = stoi(tokens[2]);
				tableIdToMenuQuantityMap[t] -= 1;
			} else if (tokens.size() == 2) {
				int t = stoi(tokens[1]);

				if (tableIdToMenuQuantityMap[t] == 0) {
					cout << tableIdToMenuCostMap[t] << '\n';
					tableIdToMenuQuantityMap[t] = 0;
					tableIdToMenuCostMap[t] = 0;
				} else {
					cout << "please wait\n";
				}
			}
		}
	}


	// string line;
	// int index = 1;
	// while (!cin.eof()) {
	//   getline(cin, line);
	//   cout << "line[" << index++ << "]:" << line << "\n";
	// }
	return 0;
}
