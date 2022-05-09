#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n = 100;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		cin >> n;

		vector<int> a;
		long long sum = 0;
		for (int i = 0; i < 30; ++i) {
			sum += 1 << i;
			cout << (1 << i) << " ";
		}
		int inf = 1e9;
		for (int i = 0; i < n - 30; ++i) {
			a.push_back(inf - i);
			sum += inf - i;
			cout << inf - i << " ";
		}
		cout << endl;

		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			a.push_back(x);
			sum += x;
		}

		sum /= 2;

		vector<int> ans;
		for (auto x : a) {
			if (sum >= x) {
				ans.push_back(x);
				sum -= x;
			}
		}
		for (int i = 29; i >= 0; i--)
			if (sum >> i & 1) {
				sum -= 1 << i;
				ans.push_back(1 << i);
			}

		for (auto x : ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}

