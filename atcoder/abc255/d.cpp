#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	for (auto &x : a) cin >> x;
	vector<long long> l(n + 1), r(n + 1);
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; ++i)
		l[i] = l[i - 1] + a[i - 1];
	for (int i = n - 1; i >= 0; --i)
		r[i] = r[i + 1] + a[i];


	for (int i = 0; i < q; ++i) {
		long long x;
		cin >> x;

		long long res = 0;
		if (x <= a[0]) cout << l[n] - x * n << '\n';
		else if (x >= a.back()) cout << x * n - l[n] << '\n';
		else {
			int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
			cout << x * idx - l[idx] - x * (n - idx) + r[idx] << '\n';

		}
	}
	return 0;
}

