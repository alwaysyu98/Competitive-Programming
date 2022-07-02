#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<pair<int, int>> f {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

	long long res = 0;
	for (auto [x, y] : f)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				long long tmp = 0;
				for (int t = 0; t < n; ++t)
					tmp = tmp * 10 + a[(i + t * x + n) % n][(j + t * y + n) % n] - '0';
				res = max(res, tmp);
			}

	cout << res;
	return 0;
}

