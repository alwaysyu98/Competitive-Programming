#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<array<long long, 3>> a(n);
	for (auto &[x, y, p] : a) cin >> x >> y >> p;

	const long long inf = 0x3f3f3f3f3f3f3f3f;
	vector g(n, vector<long long> (n, inf));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j) {
				long long t = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
				if (t % a[i][2]) g[i][j] = t / a[i][2] + 1;
				else g[i][j] = t / a[i][2];
			} else g[i][j] = 0;

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));

	auto check = [&](long long mid) {
		for (int i = 0; i < n; ++i) {
			int ct = 0;	
			for (int j = 0; j < n; ++j)
				if (g[i][j] <= mid) ct += 1;
			if (ct == n) return true;
		}
		return false;
	};

	long long l = 0, r = 4000000000;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l;
	return 0;
}

