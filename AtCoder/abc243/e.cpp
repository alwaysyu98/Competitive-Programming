#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	using ll = long long;
	const ll inf = 0x3f3f3f3f3f3f3f3f;
	int n, m, x, y, z;
	cin >> n >> m;
	vector<vector<ll>> g(n + 1, vector<ll> (n + 1, inf));
	vector<array<int, 3>> edges(m);
	for (int i = 1; i <= n; ++i) g[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		edges[i] = {x, y, z};
		g[x][y] = z;
		g[y][x] = z;
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	ll ans = 0;
	for (auto &[x, y, z] : edges) {
		int t = 0;
		for (int i = 1; i <= n; ++i)
			if (g[x][i] + g[i][y] <= z && i != x && i != y)
				t = 1;
		ans += t;
	}

	cout << ans;
	return 0;
}
