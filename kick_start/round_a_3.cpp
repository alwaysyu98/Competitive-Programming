#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;
	string s;

	for (int tt = 1; tt <= t; ++tt) {
		cin >> n >> s;
		bool ok = false;

		function<void(int,int)> solve = [&](int i, int len) {
			if (ok == true) return;
			if (i + len - 1 == n) {
				ok = true;
				return; 
			}

			int ct = 0;
			for (int j = 0; j < len / 2; ++j) {
				int a = i + j, b = i + len - 1 - j;
				if (s[a] != '?' && s[b] != '?') {
					if (s[a] == s[b]) ct++;
					else {
						solve(i + 1, len);
						return;
					}
				} else if (s[a] != '?' && s[b] == '?') {
					char tmp = s[a];
					s[b] = '1' - s[a];
					solve(i + 1, len);
					s[a] = tmp, s[b] = '?'; 
				} else if (s[a] == '?' && s[b] != '?') {
					char tmp = s[b];
					s[a] = '1' - s[b];
					solve(i + 1, len);
					s[a] = '?', s[b] = tmp;
				} else {
					s[a] = '1', s[b] = '0';
					solve(i + 1, len);
					s[a] = '0', s[b] = '1';
					solve(i + 1, len);
					s[a] = '?', s[b] = '?';
				}
			}

			if (ct == len / 2) ok = false;
			return;
		};

		solve(0, 6);
		solve(0, 5);
		if (ok) cout << "Case #" << tt << ": " << "POSSIBLE" << "\n";
		else cout << "Case #" << tt << ": " << "IMPOSSIBLE" << "\n";

	}
	return 0;
}
