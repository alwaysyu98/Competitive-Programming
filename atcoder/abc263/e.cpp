#include <bits/stdc++.h>

using namespace std;

long long qpow(long long a, long long b, long long d) {
	long long x = a, y = 1;
	for (; b; b >>= 1) {
		if (b & 1) y = (y * x) % d;
		x = (x * x) % d;
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const long long mod = 998244353;

	int n;
	cin >> n;
	vector<long long> a(n - 1);
	for (auto &x : a) cin >> x;

	vector<long long> b(n + 1);
	for (int i = n - 2; i >= 0; --i) {
		long long now = (b[i + 1] - b[i + a[i] + 1] + mod) % mod;
		now = ((((now + 1) % mod) * qpow(a[i], mod - 2, mod)) % mod + 1) % mod;
		b[i] = (b[i + 1] + now) % mod;
		if (i == 0) cout << now;
	}

	return 0;
}
