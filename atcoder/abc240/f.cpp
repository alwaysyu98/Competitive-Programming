#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		long long ans = LLONG_MIN;
		cin >> n >> m;
		vector<long long> x(n + 1), y(n + 1);
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];
		vector<long long> a(n + 1), b(n + 1), c(n + 1);
		for (int i = 1; i <= n; ++i)
			b[i] = b[i - 1] + 1ll * x[i - 1] * y[i - 1];
		for (int i = 1; i <= n; ++i)
			a[i] = a[i - 1] + 1ll * b[i - 1] * y[i - 1] + 1ll * x[i - 1] * (y[i - 1] + 1) * y[i - 1] / 2ll; 
		for (int i = 1; i <= n; ++i) {
			long long ans1 = 1ll * a[i - 1] + b[i - 1] + x[i - 1];
			long long ans2 = a[i];
			ans = max(ans, ans1);
			ans = max(ans, ans2);
			if (x[i - 1] == 0) continue;
			int k1 = b[i - 1] / (-1 * x[i - 1]), k2 = k1 + 1, k3 = k1 - 1;
			if (k1 >= 1 && k1 <= y[i - 1])
				ans = max(ans, 1ll * a[i - 1] + b[i - 1] * k1 + x[i - 1] * (k1 + 1) * k1 / 2);
			if (k2 >= 1 && k2 <= y[i - 1])
				ans = max(ans, 1ll * a[i - 1] + b[i - 1] * k2 + x[i - 1] * (k2 + 1) * k2 / 2);
			if (k3 >= 1 && k3 <= y[i - 1])
				ans = max(ans, 1ll * a[i - 1] + b[i - 1] * k3 + x[i - 1] * (k3 + 1) * k3 / 2);
		}
		cout << ans << "\n";
	}
	return 0;
}
