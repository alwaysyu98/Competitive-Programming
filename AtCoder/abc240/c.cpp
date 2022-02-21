#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<bool> f(x + 1, false);
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	f[0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = x; j >= 0; --j) {
			f[j] = false;
			if (a[i] <= j)
				f[j] = f[j] || f[j - a[i]];
			if (b[i] <= j)
				f[j] = f[j] ||f[j - b[i]];
		}
	}

	if (f[x]) cout << "Yes";
	else cout << "No";
	return 0;
}
