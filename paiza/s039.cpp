#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> m >> n;
	vector<vector<char>> g(m, vector<char> (n));
	
	for (int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> g[i][j];

	vector<vector<int>> a(m, vector<int> (n));

	for (int j = 0; j < n; ++j)
		for (int i = 0, t = 0; i < m; ++i)
			a[i][j] = (g[i][j] == '#' ? t = 0 : ++t);

	int maxx = 0;
	for (int i = 0; i < m; ++i) {
		stack<int> stk;
		vector<int> left(n), right(n, n);
		for (int j = 0; j < n; ++j) {
			while (stk.size() && a[i][stk.top()] >= a[i][j]) stk.pop();
			left[j] = stk.size() ? stk.top() : -1;
			stk.push(j);
		}

		stk = stack<int> ();
		for (int j = n - 1; j >= 0; --j) {
			while (stk.size() && a[i][stk.top()] >= a[i][j]) stk.pop();
			right[j] = stk.size() ? stk.top() : n;
			stk.push(j);
		}

		for (int j = 0; j < n; ++j)
			maxx = max(maxx, (right[j] - left[j] - 1) * a[i][j]);
	}

	cout << maxx;
	return 0;
}

