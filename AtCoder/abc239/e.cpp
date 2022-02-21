#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, y;
	cin >> n >> m;
	vector<int> g[n + 1], w(n + 1), k(n + 1), v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 1; i <= n - 1; ++i) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= m; ++i)
		cin >> v[i] >> k[i];

	vector<int> st(n + 1);
	vector<vector<int>> f(n + 1);
	function<void(int)> solve = [&](int x) {
		st[x] = 1;
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(w[x]);
		for (auto v : g[x]) {
			if (st[v] == 1) continue;
			solve(v);
			for (auto y : f[v]) {
				if (pq.size() < 20)
					pq.push(y);
				else if (pq.top() < y) {
					pq.pop();
					pq.push(y);
				}
			}
		}
		while (pq.size()) {
			f[x].push_back(pq.top());
			pq.pop();
		}
		reverse(f[x].begin(), f[x].end());
	};
	solve(1);

	for (int i = 1; i <= m; ++i)
		cout << f[v[i]][k[i] - 1] << "\n";
			
	return 0;
}
