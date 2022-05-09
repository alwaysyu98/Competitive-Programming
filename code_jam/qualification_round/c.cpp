#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	auto check = [&](int mid, vector<int> &s) {
		int t = mid;
		if (t > s.size()) return false;
		for (int i = 0; i < s.size(); ++i)
			if (t <= s[i]) {
				t--;
				if (!t) return true;
			}
			else return false;
		return true;
	};

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		int n;
		cin >> n;
		vector<int> s(n);
		for (auto &x : s)
			cin >> x;

		sort(s.begin(), s.end(), greater<int> ());
		int l = 1, r = s[0];
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (check(mid, s)) l = mid;
			else r = mid - 1;
		}
		cout << l << "\n";
	}
	return 0;
}
