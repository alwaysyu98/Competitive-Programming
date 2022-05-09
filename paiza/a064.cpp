#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	using pii = pair<int, int>;
	pii s, e;
	cin >> s.second >> s.first >> e.second >> e.first;

	int m, n, h;
	cin >> n >> m >> h;
	vector<vector<bool>> vis(m + 1, vector<bool> (n + 1));
	vector<tuple<int, int, int, int>> nums(h);
	unordered_map<char, int> g {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

	for (int i = 0; i < h; ++i) {
		int x, y, l;
		char ch;
		cin >> ch >> l >> y >> x;
		nums[i] = {x, y, l, g[ch]};
	}

	auto check = [&](int x, int y) {
		for (int i = 0; i < h; ++i) {
			auto [nx, ny, l, ds] = nums[i];	
			if (ds == 1 && y - ny >= 0 && y - ny <= l && abs(x - nx) <= abs(ny - y)) return false;
			else if (ds == 3 && ny - y >= 0 && ny - y <= l && abs(x - nx) <= abs(ny - y)) return false; 
			else if (ds == 2 && x - nx >= 0 && x - nx <= l && abs(y - ny) <= abs(nx - x)) return false;
			else if (ds == 0 && nx - x >= 0 && nx - x <= l && abs(y - ny) <= abs(nx - x)) return false;
		}
		return true;
	};

	queue<pii> q;
	q.push(s);
	vis[s.first][s.second] = true;

	vector<int> dir {-1, 0, 1, 0, -1};
	while (q.size()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			auto [x, y] = q.front();
			q.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = x + dir[j], ny = y + dir[j + 1];
				if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
				if (vis[nx][ny]) continue;
				if (nx == e.first && ny == e.second) {
					cout << "YES";
					return 0;
				}
				if (!check(nx, ny)) continue;
				vis[nx][ny] = true;
				q.emplace(nx, ny);
			}
		}
	}

	cout << "NO";
	return 0;
}

