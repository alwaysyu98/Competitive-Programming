#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 10000000;

	auto get = [&](int x) {
		int ct = 0;
		while (x) {
			if (x % 10 == 1) ct += 1;
			x /= 10;
		}
		return ct;
	};

	long long ct = 0;
	for (int i = 1; i <= n; ++i) {
		if (i % 3 == 0 || i % 5 == 0) continue;
		ct += get(i);
	}

	cout << ct;
	return 0;
}

