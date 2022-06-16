#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	vector<int> w(n);
	for (auto &x : w) cin >> x;
	cin >> m;
	vector<int> a(m), c(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i] >> c[i];

	const int inf = 0x3f3f3f3f;
	vector f(n + 1, vector<int> (101, inf));

	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k <= 100; ++k) {
			if (k >= w[i - 1])
				f[i][k - w[i - 1]] = min(f[i][k - w[i - 1]], f[i - 1][k]);
			for (int j = 0; j < m; ++j)
				if (a[j] >= w[i - 1])
					f[i][a[j] - w[i - 1]] = min(f[i][a[j] - w[i - 1]], f[i - 1][k] + c[j]);
		}

	int ans = inf;
	for (int i = 0; i <= 100; ++i)
		ans = min(ans, f[n][i]);

	cout << ans;
	return 0;
}
