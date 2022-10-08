#include <bits/stdc++.h>

using namespace std;

struct UF {
	vector<int> a, sz;
	vector<bool> ok;
	int n, m;
	int res = 0;
	UF(int n, int m) : n(n), m(m), a(n + m + 1), sz(n + m + 1), ok(n + m + 1){
		for (int i = 0; i <= n + m; ++i)
			a[i] = i;
		for (int i = 0; i <= n; ++i)
			ok[i] = false, sz[i] = 1;
		for (int i = n + 1; i <= n + m; ++i)
			ok[i] = true, sz[i] = 0;
	}

	int find(int x) {
		if (a[x] != x) a[x] = find(a[x]);
		return a[x];
	}

	void merge(int x, int y) {
		int rx = find(x), ry = find(y);
		if (rx == ry) return;
		if (sz[rx] > sz[ry]) swap(rx, ry);
		a[rx] = ry;
		
		if (ok[rx] && ok[ry])
			ok[ry] = true;
		else if (!ok[rx] && !ok[ry])
			ok[ry] = false;
		else if (!ok[rx] && ok[ry]) {
			ok[ry] = true, res += sz[rx];
		} else ok[ry] = true, res += sz[ry];

		sz[ry] += sz[rx];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, e, q;
	cin >> n >> m >> e;
	vector<pair<int, int>> edges(e);
	for (auto &[a, b] : edges)
		cin >> a >> b;

	cin >> q;
	vector<int> qe(q);
	for (auto &x : qe)
		cin >> x;
	UF uf(n, m);

	vector<int> ans(q);
	vector<bool> vis(e, true);
	reverse(qe.begin(), qe.end());
	for (auto x : qe)
		vis[x - 1] = false;
	
	for (int i = 0; i < e; ++i)
		if (vis[i]) {
			auto [a, b] = edges[i];
			uf.merge(a, b);
		}

	for (int i = 0; i < q; ++i) {
		auto [a, b] = edges[qe[i] - 1];
		ans[i] = uf.res;
		uf.merge(a, b);
	}

	reverse(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << '\n';
	return 0;
}
