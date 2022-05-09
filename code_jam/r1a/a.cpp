#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		string s, ans;
		cin >> s;
		int n = s.size();

		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n && s[j] == s[i]) j++;

			if (j < n && s[j] > s[i]) ans += string(j - i, s[i]);
			ans += string(j - i, s[i]);

			i = j;
		}

		cout << "Case #" << tt << ": " << ans << "\n";
	}
	return 0;
}
