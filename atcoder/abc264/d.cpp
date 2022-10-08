#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	const int n = 7;
	string p = "atcoder";

	vector<int> a(n);
	unordered_map<char, int> g;
	for (int i = 1; i < n; ++i)
		g[p[i]] = i;
	for (int i = 0; i < n; ++i)
		a[i] = g[s[i]];

	int sum = 0;
	function<void(int, int)> solve = [&](int l, int r) {
		if (l >= r) return;
		int i = l, mid = l + r >> 1, j = mid + 1;
		solve(l, mid), solve(mid + 1, r);
		vector<int> tmp(r - l + 1);
		int k = 0;
		while (i <= mid && j <= r) {
			if (a[i] <= a[j]) tmp[k++] = a[i++];
			else sum += mid - i + 1, tmp[k++] = a[j++];
		}
		while (i <= mid) tmp[k++] = a[i++];
		while (j <= r) tmp[k++] = a[j++];
		for (int t = l, tt = 0; t <= r; ++t, ++tt)
			a[t] = tmp[tt];
	};

	solve(0, 6);
	cout << sum;
	return 0;
}
