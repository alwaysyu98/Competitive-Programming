#include <bits/stdc++.h>

using namespace std;

int f[250][250];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; ++i)
		f[i][i] = a[i];
	for (int l = 2; l <= n; ++l)
		for (int j = 0; j + l - 1 < n; ++j)
			for (int x = j, y = j + 1; y <= j + l - 1; x++, y++) {
				if (f[j][x] == f[y][j + l - 1])
					f[j][j + l - 1] = max(f[j][j + l - 1], f[j][x] + 1);
				ans = max(f[j][j + l - 1], ans);
			}

	cout << ans << endl;
	return 0;
}
