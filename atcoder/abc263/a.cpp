#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> a(5);
	for (auto &x : a) cin >> x;
	
	unordered_map<int, int> g;
	for (auto x : a) g[x] += 1;
	if (g.size() != 2) cout << "No";
	else {
		int t = g.begin()->second;
		if (t == 2 || t == 3) cout << "Yes";
		else cout << "No";
	}

	return 0;
}
