#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n, t;
	cin >> m >> n >> t;

	vector<vector<int>> g(m, vector<int> (n)), gg[2];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			char t;
			cin >> t;
			g[i][j] = t == 'S' ? 1 : 0;
		}
	gg[0] = g;
	gg[1] = vector<vector<int>> (m, vector<int> (n));

	vector<int> x {-1, 0, 1}, y {-1, 0, 1};

	auto print = [&](vector<vector<int>> &g) {
		cout << " ------ \n";
		for (int i = 0; i < m; ++i, cout << "\n")
			for (int j = 0; j < n; ++j)
				cout << g[i][j] << " ";
	};

	int delta = 0;
	for (int tt = 0; tt < t; ++tt) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int ct = 0;
				for (auto dx : x)
					for (auto dy : y) {
						int nx = (i + dx + m) % m, ny = (j + dy + n) % n;
						ct += gg[tt & 1][nx][ny];
					}
				gg[tt + 1 & 1][i][j] = ct & 1;
			}
		}
		print(gg[tt + 1 & 1]);
	}

	return 0;
}

