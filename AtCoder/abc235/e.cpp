#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	vector<int> p;
	UF(int n) : p(n + 1) {
		for (int i = 1; i <= n; ++i)
			p[i] = i;
	}

	int find(int x) {
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	void unite(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return;
		p[pa] = pb;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, q, u, v, w; 
	cin >> n >> m >> q;
	struct Edge {
		int u, v, w, id;
	};
	vector<Edge> edges(m + q);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		edges[i] = {u, v, w, -1};
	}
	
	for (int i = 0; i < q; ++i) {
		cin >> u >> v >> w;
		edges[i + m] = {u, v, w, i};
	}

	sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) { return a.w < b.w; });

	UF uf(n);
	vector<bool> ans(q);
	for (auto [u, v, w, id] : edges) {
		u = uf.find(u), v = uf.find(v);
		if (id != -1) {
			if (u == v) ans[id] = false;
			else ans[id] = true; 
		} else if (u != v) {
			uf.unite(u, v);
		}
	}
	
	for (auto as : ans)
		if (as) cout << "Yes\n";
		else cout << "No\n";

	return 0;
}
