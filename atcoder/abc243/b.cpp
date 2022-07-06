#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	int ct = 0, ans = 0;
	unordered_map<int, int> g;
	for (int i = 0; i < n; ++i) {
		g[a[i]] += 1;
	}

	for (int i = 0; i < n; ++i) {
		ct += a[i] == b[i];
		ans += g[b[i]] == 1 && a[i] != b[i];
	}

	cout << ct << "\n" << ans << endl;
		

	return 0;
}

