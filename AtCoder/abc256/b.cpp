#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, p = 0;
	cin >> n;
	vector<int> a(n), s(4);
	for (auto &x : a) cin >> x;

	for (int i = 0; i < n; ++i) {
		s[0] += 1;
		vector<int> t(4);

		for (int j = 0; j < 4; ++j) {
			if (j + a[i] >= 4 || j + a[i] < 0) p += s[j]; 
			else t[j + a[i]] += s[j];
		}
		s = t;
	}

	cout << p;
	return 0;
}

