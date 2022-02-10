#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<vector<bool>> f(n + 1, vector<bool> (n + 1));
	for (int i = 1; i <= n; ++i)
		f[i][i] = true;

	int ans = 1;
	for (int k = 1; k < n; ++k)
		for (int i = 1; i + k <= n; ++i)
			if (a[i] == a[i + k]) {
				if (k == 1) f[i][i + k] = true;
				else f[i][i + k] = f[i + 1][i + k - 1];	
				if (f[i][i + k]) ans = max(ans, k + 1);
			}
	cout << ans;
	return 0;
}
