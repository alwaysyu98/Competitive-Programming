#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<long long> a(n + 1), c(n + m + 1), b(m + 1);
	for (auto &x : a) cin >> x;
	for (auto &x : c) cin >> x;

	int idx = 0;
	for (int i = 0; i <= n; ++i)
		if (a[i]) {
			idx = i;
			break;
		}

	for (int i = 0; i <= m; ++i) {
		b[i] = c[i + idx] / a[idx];
		for (int j = 0; j <= n; ++j)
			c[j + i] -= a[j] * b[i];
	}

	for (auto &x : b) cout << x << " ";
	return 0;
}



