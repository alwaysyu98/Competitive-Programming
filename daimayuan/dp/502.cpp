#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y, z;
	cin >> n;
	using pil = pair<int, long long>;

	vector<vector<pil>> g(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y >> z;
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}

	const long long inf = 0x3f3f3f3f3f3f3f3f;
	vector<bool> vis(n + 1);
	vector<long long> f(n + 1), size(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
		if (g[i].size() == 1)
			v[i] = inf;

	function<void(int)> up = [&](int x) {
		vis[x] = true;
		bool ok = true;
		for (auto [y, z] : g[x]) {
			if (vis[y]) continue;
			ok = false;
			up(y);
			f[x] += min(f[y], z);
		}

		if (ok) f[x] = inf;
	};

	function<void(int)> down = [&](int x) {
		vis[x] = true;
		for (auto [y, z] : g[x]) {
			if (vis[y]) continue;
			v[y] = min((v[x] + f[x] - min(f[y], z)), z);
			down(y);
		}
	};

	up(1);
	vis = vector<bool> (n + 1);
	down(1);

	for (int i = 1; i <= n; ++i)
		cout << (f[i] == inf ? 0 : f[i]) + (v[i] == inf ? 0 : v[i]) << '\n';
	return 0;
}
