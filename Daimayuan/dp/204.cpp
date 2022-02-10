#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1), w(n + 1), l(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i] >> w[i] >> l[i];

	vector<int> f(m + 1);
	for (int i = 1; i <= n; ++i) {
		int res = l[i];
		for (int j = 1; res >= j; res -= j, j *= 2)
			for (int k = m; k >= v[i] * j; --k)
				f[k] = max(f[k], f[k - v[i] * j] + w[i] * j); 
		for (int k = m; k >= res * v[i]; --k)
			f[k] = max(f[k], f[k - res * v[i]] + w[i] * res);
	}

	cout << f[m] << endl;
	return 0;
}
