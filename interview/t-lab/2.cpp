#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 12345;
	double ans = 0;
	for (int i = 1; i <= n; i += 3) {
		ans += (0.0 + 1.0 * i * (i + 1) / (i + 2));
	}

	cout << (int)ans;
	return 0;
}

