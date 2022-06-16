#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> s(n - 1), x(m);
	for (auto &t : s) cin >> s;
	for (auto &t : s) cin >> x;

	vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i)
		a[i] = s[i - 1] - a[i - 1];

	map<long long, long long> g;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			long long c = x[j] - b[i];
		}

	return 0;
}

