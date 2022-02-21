#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int MOD = 100000000;
	int n, F;
	cin >> n >> F;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	vector<int> f(F);
	f[0] = 1;
	for (int i = 0; i < n; ++i) {
		vector<int> v(F);
		v.swap(f);
		for (int j = 0; j < F; ++j) {
			f[(j + a[i]) % F] = (f[(j + a[i]) % F] + v[j]) % MOD;
			f[j] = (f[j] + v[j]) % MOD;
		}
	}

	cout << f[0] - 1 << endl;
	return 0;
}
