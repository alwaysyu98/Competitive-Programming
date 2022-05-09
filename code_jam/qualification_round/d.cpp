#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cout << "Case #" << tt << ": ";

		int n;
		cin >> n;
		vector<long long> f(n + 1);
		vector<vector<int>> g(n + 1);
		
		for (int i = 1; i <= n; ++i)
			cin >> f[i];

		vector<int> root;
		for (int i = 1; i <= n; ++i) {
			int t;
			cin >> t;
			if (t)
				g[t].push_back(i);
			else root.push_back(i);
		}

		long long sum = 0;
		function<long long(int)> solve = [&](int i) {
			long long minn = LONG_MAX, maxx = f[i];
			for (auto nv : g[i]) {
				long long res = solve(nv);
				maxx = max(maxx, res);
				minn = min(minn, res);
			}

			if (minn == LONG_MAX) {
				sum += f[i];
				return f[i];
			} else {
				sum += max(f[i] - minn, 0ll);
				return max(minn, f[i]);
			}
		};
		
		for (auto rt : root)
			solve(rt);

		cout << sum << "\n";
	}
	return 0;
}
