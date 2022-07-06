#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &[x, y] : a)
		cin >> x >> y;
	string s;
	cin >> s;

	unordered_map<int, vector<pair<int, int>>> g;
	for (int i = 0; i < n; ++i)
		g[a[i].second].emplace_back(a[i].first, s[i] == 'R' ? 1 : -1);

	for (auto &[k, v] : g) {
		sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; } );
		bool ok = true;
		for (int i = v.size() - 1; i >= 0; --i) {
			if (v[i].second == -1)
				ok = false;
			else if (!ok) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}

