#include <iostream>

using namespace std;

int st[10], n, m;
string a[10];

int dfs(int x, int k) {
	if (k == 0) return 1;
	if (n - x < k - 1) return 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[x][i] == '#' && !st[i]) {
			st[i] = 1;
			ans += dfs(x + 1, k - 1);
			st[i] = 0;
		}
	}
	ans += dfs(x + 1, k);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == -1 && m == -1) break;
		
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << dfs(0, m) << endl;
	}
	
	return 0;
}
