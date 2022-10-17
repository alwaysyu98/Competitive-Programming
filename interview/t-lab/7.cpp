#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 40;
	vector vis(n, vector<bool> (n));
	vector ans(n, vector<char> (n));

	int ct = 0, t = 0, x = 0, y = 0, ch = 0;
	vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	for (int i = 0; i < n * n; ++i, ch = (ch + 1) % 26) {
		vis[x][y] = true;
		ans[x][y] = (char)(ch + 'A');
		int nx = x + dirs[t].first, ny = y + dirs[t].second;
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {
			t = (t + 1) % 4;
		}
		x = x + dirs[t].first, y = y + dirs[t].second;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i][i];
	}
	return 0;
}

