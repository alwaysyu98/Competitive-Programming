#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> tmp;
	function<void(int)> solve = [&](int x) {
		if (x == n) {
			for (auto x : tmp) cout << x << ' ';
			cout << '\n';
			return;
		}

		for (int i = 1; i <= m; ++i) {
			if (x == 0) {
				tmp.push_back(i);
				solve(x + 1);
				tmp.pop_back();
			}
			else if (i > tmp[x - 1]) {
				tmp.push_back(i);
				solve(x + 1);
				tmp.pop_back();
			}
		}
	};

	solve(0);
	return 0;
}
