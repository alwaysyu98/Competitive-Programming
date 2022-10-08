#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	unordered_map<int, pair<int, int>> g;
	vector<vector<pair<int, int>>> f(n);

	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int x, y;
			cin >> x >> y;
			f[i].emplace_back(x, y);

			if (!g.count(x)) g[x] = {y, 0};
			else {
				auto [a, b] = g[x];
				if (y > a) g[x] = {y, a};
				else if (y > b) g[x] = {a, y};
			}
		}
	}
	
	unordered_set<string> ct;
	for (int i = 0; i < n; ++i) {
		string tmp;
		for (auto [a, b] : f[i]) {
			auto [x, y] = g[a];
			if (b == x && y != x) tmp += to_string(a) + ":" + to_string(x - y);
		}
		ct.insert(tmp);
	}

	cout << ct.size();
	return 0;
}
