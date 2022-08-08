#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, L, R;
	cin >> n >> L >> R;
	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector f(2, vector<long long> (3));
	for (int i = 1; i <= n; ++i) {
		f[i & 1][0] = f[i - 1& 1][0] + L;
		f[i & 1][1] = min(f[i - 1 & 1][1], f[i - 1 & 1][0]) + a[i - 1];
		f[i & 1][2] = min(f[i - 1 & 1][2], f[i - 1 & 1][1]) + R;
	}

	cout << *min_element(f[n & 1].begin(), f[n & 1].end());
	return 0;
}
