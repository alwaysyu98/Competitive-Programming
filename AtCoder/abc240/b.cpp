#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, ans = 0;
	cin >> n;
	unordered_set<int> g;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		if (g.count(x) != 0) continue; 
		ans += 1;
		g.insert(x);
	}
	
	cout << ans;

	return 0;
}
