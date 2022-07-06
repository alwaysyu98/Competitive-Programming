#include <bits/stdc++.h>

using namespace std;

int f[301][301], bf[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	const int MOD = 998244353;
	int n, k;
	cin >> n >> k;
	vector<int> p(n), q(n), a(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> q[i];
	for (int i = 0; i < n; ++i)
		a[p[i]] = q[i];

	f[0][n + 1] = 1;
	for (int i = 1; i <= n; ++i) {
		memcpy(bf, f, sizeof(bf));
		memset(f, 0, sizeof(f));
		for (int j = 0; j <= k; ++j) {
			for (int q = 1; q <= n + 1; ++q) {
				if (a[i] < q && j + 1 <= k)
					f[j + 1][q] = (f[j + 1][q] + bf[j][q]) % MOD;
				f[j][min(q, a[i])] = (f[j][min(q, a[i])] + bf[j][q]) % MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n + 1; ++i)
		ans = (ans + f[k][i]) % MOD;
	cout << ans << endl;
	return 0;
}
