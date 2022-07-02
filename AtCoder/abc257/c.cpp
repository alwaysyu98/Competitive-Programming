#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<int> w(n);
	for (auto &x : w) cin >> x;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i)
		a[i].first = w[i], a[i].second = s[i] - '0';

	sort(a.begin(), a.end(), [&](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });

	vector<int> left(n + 1), right(n + 1);
	for (int i = 1; i <= n; ++i)
		left[i] += left[i - 1] + 1 - a[i - 1].second; 
	for (int i = n - 1; i >= 0; --i)
		right[i] += right[i + 1] + a[i].second;

	int maxx = 0;
	for (int i = 0; i <= n; ++i)
		if (i && a[i].first == a[i - 1].first) continue;
		else if (left[i] + right[i] > maxx)
			maxx = left[i] + right[i];

	cout << maxx;
	return 0;
}

