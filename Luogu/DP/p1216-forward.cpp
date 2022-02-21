#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> f(n + 2), a(n + 1);
	f[1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cin >> a[j];
		for (int j = i; j >= 1; --j)
			f[j + 1] = max(f[j + 1], f[j] + a[j + 1]), f[j] = max(f[j], f[j] + a[j]); 
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(f[i], ans);
	cout << ans << endl;
	return 0;
}
