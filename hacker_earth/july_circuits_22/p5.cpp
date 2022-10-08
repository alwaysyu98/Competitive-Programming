#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> f(n, 1), v(n, 1);
		set<int> g;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (a[i] <= a[j])
					f[i] = max(f[i], f[j] + 1);
				if (a[i] >= a[j])
					v[i] = max(v[i], v[j] + 1);
				if (a[i] == a[j])
					f[i] = max(f[i], max(f[j] + 1, v[j] + 1)), v[i] = max(v[i], max(v[j] + 1, f[j] + 1));
			}
			g.insert(f[i])
		}
		cout << max(*max_element(f.begin(), f.end()), *max_element(v.begin(), v.end())) << '\n';
	}

	return 0;
}

