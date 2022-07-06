#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n;
	vector<int> g[n + 1];
	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<bool> st(n + 1);
	vector<vector<int>> ans(n + 1, vector<int> (2));
	int ct = 1;
	function<int(int, int)> dfs = [&](int x, int pos) {
		st[x] = true;
		int tmp = pos;
		for (auto &v : g[x]) {
			if (st[v]) continue;
			int res = dfs(v, tmp);
			tmp = res + 1;
		}
		ans[x][0] = pos, ans[x][1] = max(pos, tmp - 1);
		return max(pos, tmp - 1);
	};

	dfs(1, 1);
	for (int i = 1; i <= n; ++i)
		cout << ans[i][0] << " " << ans[i][1] << "\n";
	return 0;
}
