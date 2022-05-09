#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int N = 3000010;
	int n;
	cin >> n;
	unordered_map<int, vector<pair<int, int>>> g;
	vector<int> a(n), b(n), f(2 * n + 1), alls(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		alls[2 * i] = a[i], alls[2 * i + 1] = b[i]; 
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	auto find = [&](int x) {
		return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1; 
	};

	for (int i = 0; i < n; ++i) {
		int ida = find(a[i]), idb = find(b[i]);
		g[idb].push_back({ida, b[i] - a[i] + 1});
	}
	
	for (int i = 1; i <= 2 * n; ++i) {
		f[i] = f[i - 1];
		for (auto &v : g[i])
			f[i] = max(f[i], f[v.first - 1] + v.second);
	}

	cout << f[2 * n] << endl;
	return 0;
}
