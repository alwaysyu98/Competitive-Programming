#include <bits/stdc++.h>

using namespace std;

long long a[100001], f[400001], v[400001];

void build(int k, int l, int r) {
	v[k] = 0;
	if (l == r) {
		f[k] = a[l];
		return;
	}
	int m = l + r >> 1;
	build(k + k, l, m);
	build(k + k + 1, m + 1, r);
	f[k] = f[k + k] + f[k + k + 1];
}

void insert(int k, int l, int r, int x, int y, long long z) {
	if (l == x && r == y) {
		v[k] += z;
		return;
	}
	v[k + k] += v[k], v[k + k + 1] += v[k], v[k] = 0;
	int m = l + r >> 1;
	if (y <= m)
		insert(k + k, l, m, x, y, z);
	else if (x > m)
		insert(k + k + 1, m + 1, r, x, y, z);
	else insert(k + k, l, m, x, m, z), insert(k + k + 1, m + 1, r, m + 1, y, z);

	f[k] = f[k + k] + v[k + k] * (m - l + 1) + f[k + k + 1] + v[k + k + 1] * (r - m);
}

long long calc(int k, int l, int r, int x, int y) {
	if (l == x && r == y)
		return f[k] + v[k] * (r - l + 1);

	v[k + k] += v[k], v[k + k + 1] += v[k], v[k] = 0;
	int m = l + r >> 1;
	long long tmp = 0;
	if (y <= m)
		tmp = calc(k + k, l, m, x, y);
	else if (x > m)
		tmp = calc(k + k + 1, m + 1, r, x, y);
	else tmp = calc(k + k, l, m, x, m) + calc(k + k + 1, m + 1, r, m + 1, y);

	f[k] = f[k + k] + v[k + k] * (m - l + 1) + f[k + k + 1] + v[k + k + 1] * (r - m);
	return tmp;
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
	for (int i = 1; i <= m; ++i) {
		int t, x, y;
		long long k;
		cin >> t;
		if (t == 1) {
			cin >> x >> y >> k;
			insert(1, 1, n, x, y, k);
		} else {
			cin >> x >> y;
			cout << calc(1, 1, n, x, y) << "\n";
		}
	}
	
	return 0;
}
