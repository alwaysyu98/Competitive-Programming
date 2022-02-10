#include <bits/stdc++.h>

using namespace std;
int n, m;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int> (n + 1, INF));
	vector<int> f(n + 1, INF);

	int x, y, z;
	while (m--) {
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}

	f[1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)	
			f[i] = min(f[i], f[j] + g[j][i]);

	cout << f[n] << endl;
	return 0;
}
