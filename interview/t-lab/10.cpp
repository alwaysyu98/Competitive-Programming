#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	vector<int> t(7);
	int ans = 0;
	for (int i = 0; i < 9999999; ++i) {
		int tmp = i;
		for (int j = 0; j < 7; ++j) {
			t[j] = tmp % 10;
			tmp /= 10;
		}

		int ct = 0, maxx = 0;
		for (int j = 0; j < 7; ++j) {
			if (maxx > t[j]) continue;
			maxx = max(t[j], maxx);
			ct += 1;
		}
		if (ct == 2) ans += 1;
	}

	cout << ans;
	return 0;
}

