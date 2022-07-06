#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), v(n), w(n);
	unordered_map<int, vector<int>> g;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> v[i] >> w[i];
		g[a[i]].push_back(i);
	}

	vector<int> f(m + 1);
	for (auto &[k, gp] : g)
		for (int j = m; j; --j)
			for (int i = 0; i < gp.size(); ++i)
				if (j >= v[gp[i]])
					f[j] = max(f[j], f[j - v[gp[i]]] + w[gp[i]]);

	cout << f[m] << endl;
	return 0;
}
