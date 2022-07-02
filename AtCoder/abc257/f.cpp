#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, u, v;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	auto bfs = [&](int x, vector<int> &ans) {
		queue<int> q;
		vector<bool> vis(n + 1);
		vis[x] = true;
		q.push(x);
		int step = 0;

		while (q.size()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto t = q.front();
				q.pop();
				ans[t] = step;	

				for (auto nv : g[t]) {
					if (vis[nv]) continue;
					vis[nv] = true;
					q.push(nv);
				}
			}
			step += 1;
		}
	};

	const int inf = 0x3f3f3f3f;
	vector<int> res0(n + 1, inf), res1(n + 1, inf);
	bfs(1, res0), bfs(n, res1);

	for (int i = 1; i <= n; ++i) {
		int t = min(res0[n], min(res0[0] + res1[i], res0[i] + res1[0]));
		if (t == inf) cout << -1 << " ";
		else cout << t << " ";
	}
	return 0;
}

