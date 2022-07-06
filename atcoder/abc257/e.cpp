#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> c(9);
	for (auto &x : c) cin >> x;

	vector<int> f(n + 1);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j < 9; ++j)
			if (i - c[j] >= 0)
				f[i] = max(f[i], f[i - c[j]] + 1);

	string ans;
	while (f[n] > 0) {
		int x = 9;
		while (c[x] > n || f[n - c[x]] != f[n] - 1) x--;
		ans += (x + '1');
		n -= c[x];
	}

	cout << ans;
	return 0;
}

