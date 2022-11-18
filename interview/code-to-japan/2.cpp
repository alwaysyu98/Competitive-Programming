#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<long long> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector<vector<long long>> f(m + 1, vector<long long> (1 << n, LONG_MAX));
	f[0][0] = 0;
	sort(a.begin(), a.end(), greater<long long> ());
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			int ct = __builtin_popcount(j);
			if (ct > b[i]) continue;

			long long sum = 0;
			bool ok = false, next = false;
			for (int t = 0; t < n; ++t) {
				if (!(j & (1 << t))) continue;
				sum += a[t];
				if (sum >= b[i] && ok) next = true;
				if (sum >= b[i] && !ok) ok = true;
			}
			if (next) continue;
			if (sum > 0 && sum < b[i]) continue;

			for (int k = j; k < (1 << n); ++k) {
				if ((k & j) != j) continue;
				long long t = k - j, delta = 0;
				if (j == 0) delta = b[i] * x;
				else delta = (ct - 1) * y;
				if (f[i][t] == LONG_MAX) continue;
				f[i + 1][k] = min(f[i + 1][k], f[i][t] + delta);
			}
		}
	}

	cout << *min_element(f[m].begin(), f[m].end());
	return 0;
}

