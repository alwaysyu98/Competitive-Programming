#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

	vector g(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			g[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);

	const int inf = 0x3f3f3f3f;
	vector<bool> vis(n);
	vector<int> dis(n, inf);

	int res = 0;
	dis[0] = 0;
	for (int i = 0; i < n; ++i) {
		int t = -1;
		for (int j = 0; j < n; ++j) 
			if (!vis[j] && (t == -1 || dis[t] > dis[j]))
				t = j;
		if (dis[t] == inf) break;
		res += dis[t];
		vis[t] = true;
		for (int j = 0; j < n; ++j)
			dis[j] = min(dis[j], g[t][j]);
	}

	cout << res;

	return 0;
}
