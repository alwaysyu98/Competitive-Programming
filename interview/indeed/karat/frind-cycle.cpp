#include <bits/stdc++.h>

using namespace std;

struct UF {
	int n;
	vector<int> a, sz;
	UF(int n) : n(n), a(n + 1), sz(n + 1) {
		for (int i = 0; i <= n; ++i)
			a[i] = i, sz[i] = 1;
	}
	int find(int x) {
		if (a[x] != x) a[x] = find(a[x]);
		return a[x];
	}
	void merge(int x, int y) {
		int ra = find(x), rb = find(y);
		if (ra == rb) return;
		if (sz[ra] >= sz[rb]) swap(rb, ra);
		a[ra] = rb;
		sz[rb] += sz[ra];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	vector<pair<int, string>> a {{1, "Engineer"}, {2, "HR"}, {3, "Engineer"}, {4, "Business"}, {6, "Engineer"}};
	vector<pair<int, int>> b {{1, 2}, {1, 3}, {3, 4}};

	int n = a.size(), m = b.size();
	unordered_map<int, int> st;
	unordered_map<string, int> ct1, ct2;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n; ++i)
		st[a[i].first] = i, ct1[a[i].second] += 1;

	UF uf(n);
	for (int i = 0; i < m; ++i) {
		int x = st[b[i].first], y = st[b[i].second];
		g[x].push_back(y);
		g[y].push_back(x);
		if (a[x].second != a[y].second)
			ct2[a[x].second] += 1, ct2[a[y].second] += 1;
		uf.merge(x, y);
	}

	// q1
	for (int i = 0; i < n; ++i) {
		cout << a[i].first << ": ";
		for (auto j : g[i])
			cout << a[j].first << " ";
		cout << "\n";
	}

	// q2
	for (auto &[k, v] : ct1)
		cout << k << ": " << ct2[k] << " of " << v << "\n";

	// q3
	vector<vector<int>> ans(n + 1);
	for (int i = 0; i < n; ++i) {
		int ri = uf.find(i);
		ans[ri].push_back(i);
	}

	for (int i = 0; i < n; ++i)
		if (ans[i].size()) {
			for (auto j : ans[i])
				cout << a[j].first << " ";
			cout << "\n";
		}
	
	return 0;
}
