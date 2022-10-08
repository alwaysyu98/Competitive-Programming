#include <bits/stdc++.h>

using namespace std;

// must use greedy algorithm to optimize and pre-process the input.
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int s, n, m;
	cin >> s >> n >> m;
	vector<vector<int>> a(n + 1, vector<int> (s));

	for (int i = 0; i < s; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[j][i];

	for (int i = 1; i <= n; ++i)
		sort(a[i].begin(), a[i].end());

	vector<int> f(m + 1);
	for (int i = 1; i <= n; ++i) {
		vector<int> v(m + 1);
		for (int j = m; j >= 0; --j)
			for (int k = 0; k < s; ++k)
				if (j >= a[i][k] * 2 + 1)
					f[j] = max(f[j], f[j - a[i][k] * 2 - 1] + (k + 1) * i);	
	}

	cout << f[m] << endl;

	return 0;
}
