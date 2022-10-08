#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x -= 1, y -= 1;
		g[x].push_back(y);
		g[y].push_back(x);
	}


	return 0;
}
