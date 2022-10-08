#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	unordered_map<char, int> g;
	for (auto x : s) g[x] += 1;
	for (auto [k, v] : g)
		if (v == 1) {
			cout << k;
			return 0;
		}

	cout << -1;
	return 0;
}
