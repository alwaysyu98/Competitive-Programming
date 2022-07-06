#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q, x;
	cin >> n >> q >> x;
	vector<long long> w(n);
	for (auto &x : w) cin >> x;

	vector<long long> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; ++i)
		a[i] = a[i - 1] + w[(i - 1) % n];

	vector<int> b(n);
	for (int i = 1; i <= n; ++i) {
		b[i - 1] = lower_bound(a.begin(), a.end(), a[i - 1] + x % a[n]) - a.begin() - i + 1;
		b[i - 1] += x / a[n] * n;
	}

	unordered_set<int> g;
	vector<int> l;
	l.push_back(0);
	int start = 0;
	g.insert(start);
	while (true) {
		int t = (start + b[start]) % n;
		l.push_back(t);
		if (g.count(t)) break;
		g.insert(t);
		start = t;
	}

	int t = l.back(), idx = 0;
	l.pop_back();
	for (int i = 0; i < l.size(); ++i)
		if (l[i] == t) idx = i;

	for (int _ = 0; _ < q; _++) {
		long long k;
		cin >> k;
		k -= 1;

		if (k < idx) cout << b[l[k]] << "\n";
		else cout << b[l[(k - idx) % (l.size() - idx) + idx]] << "\n";

	}
	return 0;
}




