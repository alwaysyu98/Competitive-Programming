#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	string s, p;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		cin >> s >> p;
		int n = s.size(), m = p.size();

		int res = 0;
		int i = 0, j = 0;
		for (; i < n && j < m; ++i) {
			int v = j;
			while (j < m && p[j] != s[i]) j++;
			res += j - v;
			if (j >= m) {
				res = -1;
				break;
			}
			j += 1;
		}
		if (i < n) res = -1;
		if (res != -1)
			res += m - j;

		cout << "Case " << "#" << tt + 1 << ": ";
		if (res == -1) cout << "IMPOSSIBLE\n";
		else cout << res << "\n";
	}
	return 0;
}
