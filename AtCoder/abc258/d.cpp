#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<long long> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	vector<long long> s(n + 1);
	long long res = LONG_MAX;
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i - 1] + b[i - 1];

	for (int i = 1; i <= x && i <= n; ++i)
		res = min(res, s[i] + (x - i) * b[i - 1]);

	cout << res;
	return 0;
}



