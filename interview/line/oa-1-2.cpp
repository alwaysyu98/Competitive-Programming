#include <bits/stdc++.h>

using namespace std;

enum RoomType {
  LOW,
  HIGH
};

enum RoomState {
  FREE,
  CLEANING,
  USED,
  WAIT
};

class Room {
public:
  int id;
  RoomType type;
  int people;
  int cost;

  // state of the room
  RoomState state = FREE;

  // start to be booked
  int startDate;
  string startTime;

  Room() {}
  Room(int id, RoomType type, int people, int cost) : id(id), type(type), people(people), cost(cost) {}
};

// room_id -> room, map
unordered_map<int, Room> roomIdToRoom;
// guest_id -> room_id, map
unordered_map<string, int> guestIdToRoomId;

using pii = pair<int, int>;
struct cmp {
  bool operator()(const pii &a, const pii & b) {
    return a.second > b.second;
  }
};

struct cmp2 {
  bool operator()(const pii &a, const pii & b) {
    RoomType typea = roomIdToRoom[a.first].type, typeb = roomIdToRoom[b.first].type;
    if (typea == typeb)
      return a.second > b.second; 
    else if (typea == HIGH) return false;
	else return true;
  }
};
// room state heap
priority_queue<pii, vector<pii>, cmp> pq;
// wait heap
priority_queue<pii, vector<pii>, cmp2> pq3;
// sales map
map<int, int> sales;

// n, m
int n, m;

// count of free clearner
int countFreeClearner = 0;

// method

int timeToInt(int date, const string &time) { 
  int idx = time.find(":");
  return date * 10000 + stoi(time.substr(0, idx)) * 100 + stoi(time.substr(idx + 1));
}

pair<int, string> intToTime(int intTime) {
  string s = to_string(intTime % 10000);
  if (s.size() != 4) s = string(4 - s.size(), '0') + s;
  s = s.substr(0, 2) + ":" + s.substr(2);
  return {intTime / 10000, s};
}

pair<int, string> addTime(int date, const string &time, int delta) {
  int intTime = timeToInt(0, time);
  int hours = intTime / 100, mins = intTime % 100;

  mins = mins + delta;
  if (mins >= 60)
    hours = (hours + 1);
  mins %= 60;

  if (hours < 24)
    return {date, intToTime((hours % 24) * 100 + mins).second};
  return {date + 1, intToTime((hours % 24) * 100 + mins).second};
}

void update(int date, const string &time) {
  int intTime = timeToInt(date, time);

  while (pq.size()) {
    auto top = pq.top();
    if (top.second <= intTime) {
      int topRoomId = pq.top().first;
      int topIntTime = pq.top().second;
      pq.pop();

      Room &room = roomIdToRoom[topRoomId];
      if (room.state == CLEANING) {
        auto [ndate, ntime] = intToTime(topIntTime);
        room.state = FREE;
        countFreeClearner += 1;
        cout << ndate << " " << ntime << " " << topRoomId << " has been cleaned.\n";

        while (pq3.size() && countFreeClearner) {
          auto [pq3RoomId, pq3IntTime] = pq3.top();
          pq3.pop();

          roomIdToRoom[pq3RoomId].state = CLEANING;
          auto [nndate, nnewTime] = addTime(ndate, ntime, 30);
          cout << ndate << " " << ntime << " A cleaner is assigned to " << pq3RoomId << ".\n";
          pq.emplace(pq3RoomId, timeToInt(nndate, nnewTime));
          countFreeClearner -= 1;
        }
      }
    } else {
      break;
    }
  }
}

int getDayOfWeek(int day) {
  return (day - 1) % 7;
}

int getCost(int date, string time, const Room &room) {
  int deltaDay = date - room.startDate;
  int start = room.startDate + 1;
  int tmp = getDayOfWeek(start);

  int deltaCost = (deltaDay / 7) * 3 * room.cost;
  
  for (int i = 0; i < (deltaDay % 7); ++i) {
    if (tmp == 5 || tmp == 6) deltaCost += 0.5 * room.cost;
    tmp = (tmp + 1) % 7;
  }

  return (date - room.startDate) * room.cost + deltaCost;
}


void clean(int date, const string &time, Room &room) {
  if (countFreeClearner == 0) {
    cout << date << " " << time << " No cleaner is available.\n";
    pq3.emplace(room.id, timeToInt(date, time));
    room.state = WAIT;
    return;
  }

  cout << date << " " << time << " A cleaner is assigned to " << room.id << ".\n";
  
  auto [ndate, newTime] = addTime(date, time, 30);
  pq.emplace(room.id, timeToInt(ndate, newTime));
  room.state = CLEANING;
  countFreeClearner -= 1;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  countFreeClearner = m;

  for (int i = 0; i < n; ++i) {
        int id, people, cost;
        string str;
        RoomType type;

        cin >> id >> str >> people >> cost;

        if (str == "LOW")
          type = LOW;
        else type = HIGH;

        Room room(id, type, people, cost);
        roomIdToRoom[id] = room;
  }

  string queryStr, token;
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
    if (query.size() != 7 && query.size() != 5 && query.size() != 4 && query.size() != 3) continue;

    if (query[2] == "check-in") { // check-in
      int date = stoi(query[0]);
      string time = query[1];
      string guestId = query[3];
      int roomId = stoi(query[4]);
      int people = stoi(query[5]);
      int day = stoi(query[6]);

      update(date, time);
      if (!roomIdToRoom.count(roomId)) {
        cout << date << " " << time << " ERROR: " << roomId << " does not exist.\n";
        continue;
      }

      Room &room = roomIdToRoom[roomId];

      if (room.people < people) {
        cout << date << " " << time << " ERROR: " << roomId << " cannot accommodate " << guestId << ".\n";
      } else if (room.state == CLEANING) {
        cout << date << " " << time << " ERROR: " << roomId << " is being cleaned.\n";
      } else if (room.state == USED) {
        cout << date << " " << time << " ERROR: " << roomId << " is occupied.\n";
      } else {
        cout << date << " " << time << " " << guestId << " successfully checked in to " << roomId << ".\n";

        guestIdToRoomId[guestId] = room.id;
        room.startDate = date;
        room.startTime = time;
        room.state = USED;

        pq.emplace(roomId, timeToInt(date, time));
      }

    } else if (query[2] == "check-out"){ // check-out
      int date = stoi(query[0]);
      string time = query[1];
      string guestId = query[3];
      int roomId = stoi(query[4]);

      update(date, time);

      if (!roomIdToRoom.count(roomId)) {
        cout << date << " " << time << " " << "ERROR: " << roomId << " does not exist.\n";
        continue;
      } else if (!guestIdToRoomId.count(guestId)) {
        cout << date << " " << time << " " << "ERROR: " << guestId << " does not exist.\n";
        continue;
      } 
      
      Room &room = roomIdToRoom[guestIdToRoomId[guestId]];
      if (room.id != roomId) {
        cout << date << " " << time << " " << "ERROR: " << guestId << " is not in " << roomId << ".\n";
      } else {
        int cost = getCost(date, time, room);
        cout << date << " " << time << " " << guestId << " has to pay " << cost << " to leave " << roomId << ".\n";
        
        sales[timeToInt(date, time)] = cost;
        clean(date, time, room);
      }
    } else if (query[2] == "status") {
      int date = stoi(query[0]);
      string time = query[1];

      update(date, time);

      int free = 0, cleaning = 0, used = 0;
      for (auto &[id, room] : roomIdToRoom) {
        if (room.state == FREE) free += 1;
        if (room.state == CLEANING || room.state == WAIT) cleaning += 1;
        if (room.state == USED) used += 1;
      }

      cout << date << " " << time << " Vacant: " << free << ", Cleaning in progress: " << cleaning << ", Occupied: " << used << "\n";
    } else if (query[2] == "sales") {
      int date = stoi(query[0]);
      string time = query[1];
      int startDate = stoi(query[3]);
      string startTime = query[4];

      int endDate = 101;
      string endTime = "19:19";
      if (query.size() == 7)
        endDate = stoi(query[5]), endTime = query[6];

      int startIntTime = timeToInt(startDate, startTime), endIntTime = timeToInt(endDate, endTime);
      auto p1 = sales.lower_bound(startIntTime);
      auto p2 = sales.lower_bound(endIntTime);

      int sum = 0;
      while (p1 != sales.end() && p1 != p2) {
        sum += p1->second;
        p1++;
      }

      cout << date << " " << time << " Sales: " << sum << "\n";
    }
  }
  update(101, "19:19");
  return 0;
}
