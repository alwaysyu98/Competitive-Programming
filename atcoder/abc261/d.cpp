#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	using pii = pair<int, int>;
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	vector<pii> c(m);
	for (auto &_ : x) cin >> _;
	for (auto &[a, b] : c) cin >> a >> b;

	unordered_map<int, int> g;
	for (auto [a, b] : c)
		g[a] = b;

	vector f(n + 1, vector<long long> (n + 1, LONG_MIN));

	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = *max_element(f[i - 1].begin(), f[i - 1].end());
		for (int j = 1; j <= i; ++j) {
			f[i][j] = max(f[i - 1][j - 1] + g[j] + x[i - 1], f[i][j]);
		}
	}

	cout << *max_element(f[n].begin(), f[n].end());
	return 0;
}
