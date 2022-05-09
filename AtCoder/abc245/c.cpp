#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	bool f[2][2];
	memset(f, 0, sizeof(f));

	f[0][0] = f[0][1] = true;
	for (int i = 1; i < n; ++i) {
		f[i & 1][0] = (f[i - 1 & 1][0] && abs(a[i - 1] - a[i]) <= k) || (f[i - 1 & 1][1] && abs(b[i - 1] - a[i]) <= k);
		f[i & 1][1] = (f[i - 1 & 1][0] && abs(a[i - 1] - b[i]) <= k) || (f[i - 1 & 1][1] && abs(b[i - 1] - b[i]) <= k);
	}

	if (f[n - 1 & 1][0] || f[n - 1 & 1][1]) cout << "Yes";
	else cout << "No";

	return 0;
}


