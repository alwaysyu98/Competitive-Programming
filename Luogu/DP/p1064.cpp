#include <bits/stdc++.h>

using namespace std;

struct Item {
	int v, p, q;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> m >> n;
	vector<Item> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i].v >> a[i].p >> a[i].q;

	vector<vector<Item>> g(n + 1);
	for (int i = 1; i <= n; ++i)
		if (a[i].q)
			g[a[i].q].push_back(a[i]);

	vector<int> f(m + 1);
	for (int i = 1; i <= n; ++i) {
		if (a[i].q) continue;
		for (int j = m; j >= 0; --j) {
			if (j >= a[i].v)
				f[j] = max(f[j], f[j - a[i].v] + a[i].v * a[i].p);
			if (g[i].size() >= 1 && j - a[i].v - g[i][0].v >= 0)
				f[j] = max(f[j], f[j - a[i].v - g[i][0].v] + a[i].v * a[i].p + g[i][0].v * g[i][0].p);
			if (g[i].size() == 2) {
				if (j - a[i].v - g[i][1].v >= 0)
					f[j] = max(f[j], f[j - a[i].v - g[i][1].v] + a[i].v * a[i].p + g[i][1].v * g[i][1].p);
				if (j - a[i].v - g[i][0].v - g[i][1].v >= 0)
					f[j] = max(f[j], f[j - a[i].v - g[i][0].v - g[i][1].v] + a[i].v * a[i].p + g[i][0].v * g[i][0].p + g[i][1].v * g[i][1].p);
			}
		}
	}

	cout << f[m] << endl;

	return 0;
}
