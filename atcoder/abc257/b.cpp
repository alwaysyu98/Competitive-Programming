#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, q;
	cin >> n >> k >> q;
	vector<int> s(n), a(k), l(q);
	for (auto &x : a) cin >> x;
	for (auto &x : l) cin >> x;

	
	for (auto x : a)
		s[x - 1] += 1;

	for (int i = 0; i < q; ++i) {
		int ct = 0, j = 0;
		for (; j < n; ++j) {
			if (s[j]) ct += 1;
			if (ct == l[i]) break;
		}
		if (j == n - 1) continue;
		if (s[j + 1]) continue;
		s[j] = 0;
		s[j + 1] = 1;
	}

	for (int i = 0; i < n; ++i)
		if (s[i])
			cout << i + 1 << " ";

	return 0;
}

