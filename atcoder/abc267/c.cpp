#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	long long tmp = 0, sum = 0, ans = LONG_MIN;
	for (int i = 0; i < n; ++i) {
		if (i < m) {
			tmp += a[i];
			sum += a[i] * (i + 1);
		} else {
			sum += a[i] * m;
			sum -= tmp;
			tmp += a[i] - a[i - m];
		}
		if (i >= m - 1) ans = max(ans, sum);
	}

	cout << ans;
	return 0;
}
