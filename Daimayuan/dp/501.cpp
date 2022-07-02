#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n;
	vector<vector<long long>> g(n + 1);

	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<long long> f(n + 1), v(n + 1), size(n + 1);
	vector<bool> vis(n + 1);
	function<void(int)> up = [&](int x) {
		vis[x] = true;
		for (auto nv : g[x]) {
			if (vis[nv]) continue;
			up(nv);
			f[x] += f[nv] + size[nv];
			size[x] += size[nv];
		}
		size[x] += 1;
	};

	function<void(int)> down = [&](int x) {
		vis[x] = true;
		for (auto nv : g[x]) {
			if (vis[nv]) continue;
			v[nv] = v[x] + f[x] - f[nv] - size[nv] + n - size[nv];
			down(nv);
		}
	};

	up(1);
	vis = vector<bool> (n + 1);
	down(1);

	for (int i = 1; i <= n; ++i)
		cout << f[i] + v[i] << '\n';
	return 0;
}
