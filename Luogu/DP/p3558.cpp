#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	const int INF = 0x3f3f3f3f;
	vector<int> f(3, INF);
	f[a[1] + 1] = 0;
	for (int i = 2; i <= n; ++i) {
		vector<int> v(3);
		v.swap(f);
		if (a[i] == 0) {
			f[0] = v[0] + 1;
			f[1] = min(v[0], v[1]);
			f[2] = v[2] + 1;
		} else if (a[i] == -1) {
			f[0] = v[0];
			f[1] = INF;
			f[2] = v[2] + 2;
		} else {
			f[0] = v[0] + 2;
			f[1] = v[0] + 1;
			f[2] = min(v[0], min(v[1], v[2]));
		}
		
	}
	int ans = min(f[0], min(f[1], f[2]));
	if (ans >= INF) cout << "BRAK";
	else cout << ans;
	return 0;
}
