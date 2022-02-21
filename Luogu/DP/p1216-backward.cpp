#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> f(n + 1), a(n);
	f[1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cin >> a[j];
		for (int j = i; j >= 1; --j)
			f[j] = max(f[j - 1] + a[j], f[j] + a[j]);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(f[i], ans);
	cout << ans << endl;
	return 0;
}
