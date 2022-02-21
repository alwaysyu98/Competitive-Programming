#include <bits/stdc++.h>

using namespace std;
int n, f[6001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), g[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n - 1; ++i) {
		cin >> x >> y;
		g[y].push_back(x);
		b[x]++;
	}

	function<void(int)> dp = [&](int x) {
		f[x][1] = a[x];
		for (auto &v : g[x]) {
			dp(v);
			f[x][1] += f[v][0];
			f[x][0] += max(f[v][0], f[v][1]);
		}
	};
	
	for (int i = 1; i <= n; ++i)
		if (b[i] == 0) {
			dp(i);	
			cout << max(f[i][0], f[i][1]) << endl;
		}

	return 0;
}
