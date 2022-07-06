#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> f(n, 1);
	f[0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
	int maxx = 0;
	for (int i = 0; i < n; ++i)
		maxx = max(maxx, f[i]);
	cout << maxx << endl;
	return 0;
}
