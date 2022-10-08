#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector f(n + 1, vector<long long> (m + 1, LONG_MIN));
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = 0;
		for (int j = 1; j <= m; ++j) {
			f[i][j] = f[i - 1][j];
			if (f[i - 1][j - 1] == LONG_MIN) continue;
			f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i] * j);
		}
	}

	cout << f[n][m];
	return 0;
}
