#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll qpow(ll a, ll b, ll k) {
	ll res = 1, t = a;
	for (; b; b >>= 1) {
		if (b & 1) res = (res * t) % k;
		t = (t * t) % k;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int mod = 998244353;

	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	vector<int> w(n);
	for (auto &x : w) cin >> x, sum += x;

	int inv = qpow(sum, mod - 2, mod);

	return 0;
}

