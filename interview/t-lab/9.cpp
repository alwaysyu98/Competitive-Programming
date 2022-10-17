#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int idx = 0;
	vector<bool> vis(10);

	int num = 0, den = 0;
	function<void()> solve = [&]() {
		if (idx == 10) {
			if (num % den == 0 && num / den == 787) {
				cout << num;
			}
			return;
		}
		int t = 0;
		if (idx == 0 || idx == 6) t = 1;
		for (int i = t; i < 10; ++i) {
			if (vis[i]) continue;

			idx += 1;
			vis[i] = true;
			if (idx <= 6) {
				num *= 10;
				num += i;
				solve();
				num /= 10;
			} else {
				den *= 10;
				den += i;
				solve();
				den /= 10;
			}
			idx -= 1;
			vis[i] = false;
		}
	};

	solve();
	return 0;
}

