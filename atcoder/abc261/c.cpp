#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &x : s) cin >> x;

	unordered_map<string, int> g;

	for (int i = 0; i < n; ++i) {
		int &t = g[s[i]];
		cout << s[i];
		if (t)
			cout << '(' << t << ")";
		cout << '\n';
		t += 1;
	}

	return 0;
}
