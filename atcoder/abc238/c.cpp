#include <bits/stdc++.h>

using namespace std;

long long qpow(int a, int b, int p) {
	long long ans = 1, t = a;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * t % p;
		t = t * t % p;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int MOD = 998244353;
	unsigned long long n;	
	long long x = qpow(2, MOD - 2, MOD);
	cin >> n;

	unsigned long long res = 0, i = 1;
	for (i = 10; i <= n; i *= 10) {
		res = res + (((i - i / 10 + 1) % MOD) * ((i - i / 10) % MOD) % MOD) * x % MOD;
		res %= MOD;
	}

	res = res + (((n - i / 10 + 2) % MOD) * ((n - i / 10 + 1) % MOD) % MOD) * x % MOD;
	res %= MOD;

	cout << res << endl;
	return 0;
}
