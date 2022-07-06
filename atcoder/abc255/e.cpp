#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> s(n - 1), x(m);
	for (auto &t : s) cin >> t;
	for (auto &t : x) cin >> t;

	long long sum = 0;
	unordered_map<long long, int> g;
	for (int i = 0; i < n; ++i) {
		if (i % 2)
			for (int j = 0; j < m; ++j)
				g[x[j] - sum] += 1;
		else
			for (int j = 0; j < m; ++j)
				g[sum - x[j]] += 1;
		sum = -sum + s[i];
	}

	int maxx = 0;
	for (auto [k, v] : g)
		maxx = max(maxx, v);

	cout << maxx;
			
	return 0;
}

