#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n;
	vector<int> g[n + 1], a(n + 1), st(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> f(n + 1);

	// f[i], look i as root of a tree and its maxium sum
	function<void(int)> solve = [&](int x) {
		st[x] = 1;
		f[x]= a[x]; 
		for (auto &v : g[x]) {
			if (st[v]) continue;
			solve(v);
			f[x]= max(f[v]+ f[x], f[x]);
		}
	};

	solve(1);
	int maxx = INT_MIN;
	for (int i = 1; i <= n; ++i)
		maxx = max(maxx, f[i]);
	cout << maxx << endl;
	return 0;
}
