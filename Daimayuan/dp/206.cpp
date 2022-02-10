#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v(n), w(n), t(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i] >> w[i] >> t[i];

	vector<vector<int>> f(k + 1, vector<int> (m + 1));

	for (int i = 0; i < n; ++i)
		for (int j1 = k; j1 >= t[i]; --j1)
			for (int j2 = m; j2 >= v[i]; --j2)
				f[j1][j2] = max(f[j1][j2], f[j1 - t[i]][j2 - v[i]] + w[i]);

	cout << f[k][m] << endl;
	return 0;
}
