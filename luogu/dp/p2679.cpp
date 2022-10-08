#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int mod = 1e9 + 7;
	int n, m, k;
	cin >> n >> m >> k;
	string a, b;
	cin >> a >> b;
	vector<vector<vector<int>>> f(m + 1, vector<vector<int>> (k + 1, vector<int> (2, 0)));
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= 1; --j)
			for (int v = k; v >= 1; --v)
				if (a[i - 1] == b[j - 1]) {
					f[j][v][0] = (f[j][v][1] + f[j][v][0]) % mod;
					f[j][v][1] = ((f[j - 1][v - 1][0] + f[j - 1][v - 1][1]) % mod + f[j - 1][v][1]) % mod;
				} else {
					f[j][v][0] = (f[j][v][0] + f[j][v][1]) % mod;
					f[j][v][1] = 0;
				}
	cout << (f[m][k][0] + f[m][k][1]) % mod << endl;
	return 0;
}
