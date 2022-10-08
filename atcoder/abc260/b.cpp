#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector<int> ans, arr(n);
	vector<bool> vis(n);
	for (int i = 0; i < n; ++i) arr[i] = i;
	stable_sort(arr.begin(), arr.end(), [&](const int &x, const int &y) { return a[x] > a[y]; });
	for (int i = 0, ct = 0; i < n && ct < x; ++i)
		ans.push_back(arr[i]), vis[arr[i]] = true, ct += 1;

	for (int i = 0; i < n; ++i) arr[i] = i;
	stable_sort(arr.begin(), arr.end(), [&](const int &x, const int &y) { return b[x] > b[y]; });
	for (int i = 0, ct = 0; i < n && ct < y; ++i)
		if (vis[arr[i]]) continue;
		else ans.push_back(arr[i]), vis[arr[i]] = true, ct += 1;

	for (int i = 0; i < n; ++i) arr[i] = i;
	stable_sort(arr.begin(), arr.end(), [&](const int &x, const int &y) { return a[x] + b[x] > a[y] + b[y]; });
	for (int i = 0, ct = 0; i < n && ct < z; ++i)
		if (vis[arr[i]]) continue;
		else ans.push_back(arr[i]), vis[arr[i]] = true, ct += 1;


	sort(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x + 1 << '\n';
	return 0;
}
