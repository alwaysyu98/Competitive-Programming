#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, t;
	cin >> n >> m >> t;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	vector<vector<int>> f(m + 1, vector<int> (t + 1));
	for (int i = 0; i < n; ++i)
		for (int j = m; j >= 0; --j)
			for (int k = t; k >= 0; --k)
				if (j >= a[i] && k >= b[i])
					f[j][k] = max(f[j][k], f[j - a[i]][k - b[i]] + 1);
	cout << f[m][t];
	return 0;
}
