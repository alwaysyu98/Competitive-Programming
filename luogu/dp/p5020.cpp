#include <bits/stdc++.h>

using namespace std;
// 这算构造题么？yy了一下就想出来了。。

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int maxx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			maxx = max(maxx, a[i]);
		}
		vector<int> f(maxx + 1);
		f[0] = 1; 
		for (int i = 0; i < n; ++i)
			for (int j = a[i]; j <= maxx; ++j)
				f[j] += f[j - a[i]];

		int ans = n;
		for (int i = 0; i < n; ++i)
			if (f[a[i]] > 1) ans--;
		cout << ans << "\n";
	}
	return 0;
}
