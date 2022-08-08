#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> p(n - 1);
	for (auto &x : p) cin >> x;

	int t = n, step = 0;
	while (t != 1) {
		step += 1;
		t = p[t - 2];
	}

	cout << step;
	return 0;
}
