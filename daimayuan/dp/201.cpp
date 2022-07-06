#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1), w(n + 1);
	for(int i = 0; i < n; ++i)
		cin >> w[i + 1] >> v[i + 1];

	// volume is excatly m
	vector<int> f(m + 1);
	f[0] = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = m; j - w[i] >= 0; --j)
			if (f[j - w[i]] >= 0) f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}
