#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, k, y;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	vector<int> a(m + 1);
	for (int i = 0; i < n - m; ++i) {
		cin >> k;
		g[i + 1].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> x >> y;
			g[i + 1][j] = {x, y};
		}
	}
	for (int i = 0; i < m; ++i)
		cin >> a[i + 1];

	const int INF = 0x3f3f3f3f;
	vector<vector<int>> f(n + 1);
	function<void(int)> solve = [&](int x) {
		if (x >= n - m + 1) {
			f[x].resize(2);
			f[x][0] = 0;
			f[x][1] = -a[x - n + m];
			return;
		}

		int sum = 0;
		for (auto &[v, w] : g[x]) {
			solve(v);
			sum += f[v].size() - 1;
		}

		f[x].resize(sum + 1, INF);
		f[x][0] = 0;
		int p = 1;
		for (auto &[v, w] : g[x]) {
			p += f[v].size();
			for (int j = min(sum, p); j >= 0; --j)
				for (int i = 1; i < f[v].size(); ++i)
					if (j - i >= 0)
						f[x][j] = min(f[x][j - i] + f[v][i] + w, f[x][j]);
		}
	};

	solve(1);
	for (int i = m; i >= 0; --i)
		if (f[1][i] <= 0) {
			cout << i << endl;
			return 0;
		}
	return 0;
}
