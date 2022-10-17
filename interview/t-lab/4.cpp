#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			int t = 0;
			for (int k = 0; k < j; ++k) {
				t = t * 10 + i;
			}
			if (t % 1434 == 0) {
				cout << t;
				break;
			}
		}
	}
	return 0;
}

