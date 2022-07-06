#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> vis(n), x(n), y(n);
	for (int i = 0; i < k; ++i) {
		int t;
		cin >> t;
		vis[t - 1] = true;
	}
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];


	double ans = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		double maxx = LONG_MAX;
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			if (!vis[j]) continue;
			double dis = 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
			maxx = min(dis, maxx);
		}
		ans = max(ans, maxx); 
	}

	cout << fixed << setprecision(6) << sqrt(ans);
	return 0;
}

