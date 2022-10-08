#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> d(n);
	for (auto &x : d) cin >> x;

	vector f(n, vector<long long> (2));
	vector<vector<pair<int, long long>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	vector<bool> vis(n);
	function<void(int)> solve = [&](int x) {
		vis[x] = true;
		
		vector<int> res;
		int sum = 0;
		for (auto [y, w] : g[x]) {
			if (vis[y]) continue;
			solve(y);
			vector<int> tmp {f[y][0] + w, f[y][0], f[y][1]};
			sort(tmp.begin(), tmp.end());
		}
		sort(res.begin(), res.end(), [&](const int &a, const int &b) { return f[a][1] < f[b][1]; });

	};
	return 0;
}
