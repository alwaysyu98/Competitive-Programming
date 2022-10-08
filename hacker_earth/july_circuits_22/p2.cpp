#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int n, a, b;
		cin >> n >> a >> b;

		if (a == b) {
			if (n == 0) cout << 0;
			else cout << -1;
		} else if (a > b) {
			if (n == a) cout << 1;
			else if (n < a) {
				cout << min(1, (n + a - b - 1) / (a - b) * 2);
			} else {
				cout << min((n + a - b - 1) / (a - b) * 2, (n - a + a - b - 1) / (a - b) * 2 + 1);
			}
		} else {
			if (n == a) cout << 1;
			else if (n > a) cout << -1;
			else cout << min(1, (n + b - a - 1) / (b - a) * 2);
		}
		cout << '\n';
	}
	return 0;
}
