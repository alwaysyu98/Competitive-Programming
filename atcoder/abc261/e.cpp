#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<int> t(n), a(n);
	for (int i = 0; i < n; ++i) cin >> t[i] >> a[i];

	vector<array<int, 32>> ct(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 30; j >= 0; --j)
			ct[i][j] = ct[i - 1][j];

		if (t[i - 1] == 1) {
			for (int j = 30; j >= 0; --j) {
				int tt = (a[i - 1] >> j) & 1;
				if (tt == 0) ct[i][j] = 3;
			}
		} else if (t[i - 1] == 2) {
			for (int j = 30; j >= 0; --j) {
				int tt = (a[i - 1] >> j) & 1;
				if (tt == 1) ct[i][j] = 4;
			}
		} else {
			for (int j = 30; j >= 0; --j) {
				int tt = (a[i - 1] >> j) & 1;
				if (tt == 0) continue;
				if (ct[i - 1][j] == 0)
					ct[i][j] = -1;
				else if (ct[i - 1][j] == -1)
					ct[i][j] = 0;
				else if (ct[i - 1][j] == 4)
					ct[i][j] = 3;
				else if (ct[i - 1][j] == 3)
					ct[i][j] = 4;
			}
		}
	}

	int x = c;
	for (int i = 0; i < n; ++i) {
		for (int j = 30; j >= 0; --j) {
			int tt = ct[i + 1][j];
			int ot = (x >> j) & 1;
			x -= (ot << j);
			if (tt == 0) x += (ot << j);
			else if (tt == -1) x += ((1 - ot) << j);
			else if (tt == 3) x += (0 << j);
			else if (tt == 4) x += (1 << j);
		}
		cout << x << '\n';
	}
	return 0;
}
