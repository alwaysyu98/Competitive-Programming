#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ct = 1, left = 5000;
	for (int i = 500; i >= 1; --i) {
		if (i > left) {
			left = 5000 - i;
			ct += 1;
		} else {
			left -= i;
		}
	}

	cout << ct;
	return 0;
}

