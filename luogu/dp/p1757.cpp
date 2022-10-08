#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> m >> n;
	unordered_map<int, vector<pair<int, int>>> g;

	int a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		g[c].emplace_back(a, b);
	}

	vector<int> f(m + 1);
	for (auto &[k, v] : g)
		for (int i = m; i >= 0; --i)
			for (auto &[a, b] : v)
				if (i >= a)
					f[i] = max(f[i], f[i - a] + b);
	
	cout << f[m];
	return 0;
}
