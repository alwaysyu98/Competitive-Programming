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
	vector<int> f1(n, 1), f2(n, 1);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (a[i] > a[j])
				f1[i] = max(f1[i], f1[j] + 1);

	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 1; j > i; --j)
			if (a[i] > a[j])
				f2[i] = max(f2[i], f2[j] + 1);

	int ans = n;
	for (int i = 0; i < n; ++i)
		ans = min(ans, n - f1[i] - f2[i] + 1);

	cout << ans << endl;
	return 0;
}
