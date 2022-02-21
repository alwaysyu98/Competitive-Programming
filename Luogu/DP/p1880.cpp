#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	const int INF = 0x3f3f3f3f;
	cin >> n;
	vector<int> b(2 * n), a(2 * n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i + n] = b[i];
	}
	for (int i = 1; i <= 2 * n; ++i)
		a[i] = a[i - 1] + b[i - 1];

	vector<vector<int>> f(2 * n, vector<int> (2 * n)), g(2 * n, vector<int> (2 * n, INF));
	for (int i = 0; i < 2 * n; ++i)
		g[i][i] = 0;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j + i < 2 * n; ++j)
			for (int k = j; k < j + i; ++k) {
				f[j][j + i] = max(f[j][k] + f[k + 1][j + i] + a[j + i + 1] - a[j], f[j][j + i]);
				g[j][j + i] = min(g[j][k] + g[k + 1][j + i] + a[j + i + 1] - a[j], g[j][j + i]);
			}

	int maxx = INT_MIN, minn = INT_MAX; 
	for (int i = 0; i + n - 1 < 2 * n; ++i)
		minn = min(minn, g[i][i + n - 1]);
	for (int i = 0; i + n - 1 < 2 * n; ++i)
		maxx = max(maxx, f[i][i + n - 1]);
	cout << minn << "\n";
	cout << maxx;
	return 0;
}
