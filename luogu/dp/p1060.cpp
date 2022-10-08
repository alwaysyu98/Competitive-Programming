#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	vector<int> f(m + 1);
	for (int i = 0; i < n; ++i)
		for (int j = m; j > a[i]; --j)
			f[j] = max(f[j], f[j - a[i]] + a[i] * b[i]);
	cout << f[m] << endl;
	return 0;
}
