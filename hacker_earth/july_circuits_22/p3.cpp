#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, k;
	string s;
	cin >> t;
	const int mod = 1e9 + 7;

	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		cin >> s;

		vector f(n + 1, vector<long long> (k + 1));
		for (int i = 0; i <= n; ++i)
			f[i][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				int t = s[i - 1] - 'a';
				if (j == 1)
					f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * t) % mod;
				else 
					f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * 25) % mod;
			}
		}

		cout << f[n][k] << '\n';
	}
	return 0;
}

