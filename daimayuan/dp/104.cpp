#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];

	vector<vector<int>> f(n + 1, vector<int> (m + 1, 0));
	vector<int> ans;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
			else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
		}

	// print subsequences with repeatations
	function<void(int, int, string)> print = [&] (int i, int j, string lcs) {
		// cout << i << " " << j << endl;
		if (i == 0 || j == 0) {
			cout << lcs << endl;
			return;
		}
		if (a[i] == b[j]) {
			print(i - 1, j - 1, to_string(a[i]) + lcs);
		} else {
			if (f[i][j - 1] >= f[i - 1][j]) print(i, j - 1, lcs);
			if (f[i - 1][j] >= f[i][j - 1]) print(i - 1, j, lcs);
		}
	};

	cout << "printf" << endl;
	print(n, m, "");
	cout << f[n][m] << endl;
	return 0;
}
