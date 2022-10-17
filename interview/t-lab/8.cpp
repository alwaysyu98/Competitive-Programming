#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 50;
	vector f(n, vector<int> (n));

	int ct = 0;
	vector g(n, vector<int> (n));
	vector vis(n, vector (n, vector<bool> (22)));
	vector<pair<int, int>> dirs {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

	function<void(int, int)> solve = [&](int x, int y) {
		if (ct == 22) {
			g[x][y] = 1;
			return;
		}
		for (int i = 0; i < 8; ++i) {
			int nx = x + dirs[i].first, ny = y + dirs[i].second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (vis[nx][ny][ct]) continue;
			vis[nx][ny][ct] = true;
			ct += 1;
			solve(nx, ny);
			ct -= 1;
		}

	};

	solve(0, 0);
	for (int i = 0; i <n ;++i) {
		for (int j = 0; j < n; ++j) {
			if (g[i][j] == 1)
				ct += 1;
		}}
	cout << ct;
	return 0;
}

