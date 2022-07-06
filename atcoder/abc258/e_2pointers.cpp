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

	vector<int> b(n);
	long long sum = 0, all = 0;
	for (auto x : w) all += x;
	for (int i = 0, j = -1; i < n; ++i) {
		while (j < 2 * n && sum < x % all) j += 1, sum += w[j % n];
		sum -= w[i];
		b[i] = j - i + 1 + x / all * n;
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
