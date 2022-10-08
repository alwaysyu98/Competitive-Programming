#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	unordered_map<int, vector<int>> g;
	g[0] = {6};
	g[1] = {3};
	g[2] = {7, 1};
	g[3] = {4, 0};
	g[4] = {8, 2};
	g[5] = {5};
	g[6] = {9};

	vector<int> t(7);
	for (int i = 0; i < 7; ++i)
		for (auto j : g[i])
			if (s[j] == '0')
				t[i] += 1;

	if (s[0] == '1') {
		cout << "No";
		return 0;
	}

	for (int i = 0; i < 7; ++i) {
		if (t[i] == g[i].size()) continue;
		for (int j = i + 2; j < 7; ++j) {
			if (t[j] == g[j].size()) continue;
			bool ok = true;
			for (int k = i + 1; k <= j - 1; ++k) {
				if (g[k].size() != t[k])
					ok = false;
			}
			if (ok) {
				cout << "Yes";
				return 0;
			}
		}
	}

	
	cout << "No";
	return 0;
}
