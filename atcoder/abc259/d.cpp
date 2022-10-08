#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, sx, sy, tx, ty;
	cin >> n >> sx >> sy >> tx >> ty;
	vector<long long> x(n), y(n), r(n);
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> r[i];
	
	vector g(n, vector<bool> (n));

	auto solve = [&](long long i, long long j) {
		long long a = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		long long b = (r[i] + r[j]) * (r[i] + r[j]);
		long long c = (r[i] - r[j]) * (r[i] - r[j]);
		return a <= b && a >= c;
	};

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (solve(i, j))
				g[i][j] = g[j][i] = true;

	auto get = [&](long long xx, long long yy) {
		for (int i = 0; i < n; ++i)
			if((x[i] - xx) * (x[i] - xx) + (y[i] - yy) * (y[i] - yy) == r[i] * r[i])
				return i;
		return -1;
	};

	int si = get(sx, sy), ti = get(tx, ty);
	assert(si >= 0 && si <= n);
	assert(ti >= 0 && ti <= n);

	vector<bool> vis(n);
	queue<int> q;
	q.push(si);
	vis[si] = true;

	while (q.size()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			auto top = q.front();
			q.pop();

			for (int j = 0; j < n; ++j) {
				if (vis[j]) continue;
				if (!g[top][j]) continue;
				vis[j] = true;
				q.push(j);
			}
		}
	}

	if (vis[ti]) cout << "Yes";
	else cout << "No";
	return 0;
}
