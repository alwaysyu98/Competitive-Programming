#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n), w(n), l(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i] >> w[i] >> l[i];

	vector<int> f(m + 1);
	deque<pair<int, int>> dq;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < v[i]; ++j) {
			dq.clear();
			for (int p = j, x = 1; p <= m; p += v[i], ++x) {
				int e = f[p] - x * w[i];
				while (dq.size() && dq.front().first < x - l[i]) dq.pop_front();
				while (dq.size() && dq.back().second <= e) dq.pop_back();
				dq.emplace_back(x, e);
				f[p] = dq.front().second + x * w[i];
			}
		}
	}
	cout << f[m] << "\n";

	return 0;
}
