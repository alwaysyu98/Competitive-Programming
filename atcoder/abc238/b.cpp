#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = (a[i] + a[i - 1]) % 360;
	}

	int ans = 0;
	sort(a.begin(), a.end());

	for (int i = 0; i <= n; ++i) {
		if (i == n)
			ans = max(ans, abs(360 - a[i]));
		else
			ans = max(ans, abs(a[i] - a[i + 1]));
	}

	cout << ans << endl;
	return 0;
}