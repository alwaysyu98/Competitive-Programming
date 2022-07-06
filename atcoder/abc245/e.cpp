#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), c(m);

	for (auto &x : a) cin >> x.first;
	for (auto &x : a) cin >> x.second;
	for (auto &x : c) cin >> x.first;
	for (auto &x : c) cin >> x.second;

	auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
		if (x.first > y.first) return true;
		else if (x.first == y.first) return x.second > y.second;
		else return false;
	};

	sort(a.begin(), a.end(), cmp);
	sort(c.begin(), c.end(), cmp);

	int i = 0, j = 0;

	auto cmp2 = [&](const pair<int, int> &x, const pair<int, int> &y) {
		if (x.second < y.second) return true;
		else return false;
	};

	multiset<pair<int, int>, decltype(cmp2)> g(cmp2);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < m && c[j].first >= a[i].first)
			g.insert(c[j++]);
		
		auto it = g.lower_bound(a[i]);
		if (it != g.end()) g.erase(it);
		else {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}




