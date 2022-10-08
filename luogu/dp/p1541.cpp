#include <bits/stdc++.h>

using namespace std;

int f[41][41][41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	cin >> n >> m;
	vector<int> a(n + 1), b(5);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		cin >> x;
		b[x] += 1;
	}

	auto sum = [](int a, int b, int c, int d) {
		return a + 2 * b + 3 * c + 4 * d;
	};
	int ans = 0;
	f[0][0][0] = a[1];
	for (int p1 = 0; p1 <= b[1]; ++p1)
		for (int p2 = 0; p2 <= b[2]; ++p2)
			for (int p3 = 0; p3 <= b[3]; ++p3)
				for (int p4 = 0; p4 <= b[4]; ++p4) {
					int target = 1 + sum(p1, p2, p3, p4);
					if (target > n) continue;
					int all = a[target];
					if (p1) f[p2][p3][p4] = max(f[p2][p3][p4], f[p2][p3][p4] + all);
					if (p2) f[p2][p3][p4] = max(f[p2][p3][p4], f[p2 - 1][p3][p4] + all);
					if (p3) f[p2][p3][p4] = max(f[p2][p3][p4], f[p2][p3 - 1][p4] + all);
					if (p4) f[p2][p3][p4] = max(f[p2][p3][p4], f[p2][p3][p4 - 1] + all);  
					if (target == n) ans = max(ans, f[p2][p3][p4]);
				}
	

	cout << ans << endl;
	return 0;
}
