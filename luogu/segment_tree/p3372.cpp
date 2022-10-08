#include <bits/stdc++.h>

using namespace std;

int a[500001], f[2000001];

void build(int k, int l, int r) {
	if (l == r) {
		f[k] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(k + k, l, m);
	build(k + k + 1, m + 1, r);
	f[k] = f[k + k] + f[k + k + 1];
}

void add(int k, int l, int r, int x, int y) {
	f[k] += y;
	if (l == r) return;
	int m = l + r >> 1;
	if (x <= m) add(k + k, l, m, x, y);
	else add(k + k + 1, m + 1, r, x, y);
}

int calc(int k, int l, int r, int x, int y) {
	if (l == x && r == y) return f[k];

	int m = l + r >> 1;
	if (y <= m) return calc(k + k, l, m, x, y);
	else if (x > m) return calc(k + k + 1, m + 1, r, x, y);
	else return calc(k + k, l, m, x, m) + calc(k + k + 1, m + 1, r, m + 1, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int k, x, y;
		cin >> k >> x >> y;
		if (k == 1)
			add(1, 1, n, x, y);
		else cout << calc(1, 1, n, x, y) << "\n";
	}
	return 0;
}
