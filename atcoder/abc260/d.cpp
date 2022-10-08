#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> p(n), ans(n + 1, -1);
	for (auto &x : p) cin >> x;

	map<int, int> g;
	vector<stack<int>> stk(n + 1);
	for (int i = 0; i < n; ++i) {
		int x = p[i];
		auto it = g.lower_bound(x);

		int t;
		if (it == g.end())
			g[x] = x, stk[x].push(x), t = x;
		else {
			t = it->second;
			stk[t].push(x);
			g.erase(it);
			g[x] = t;
		}

		if (stk[t].size() == k) {
			while (stk[t].size()) ans[stk[t].top()] = i + 1, stk[t].pop();
			g.erase(x);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i] << '\n';
	return 0;
}
