#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	long long dx = abs(x1 - x2), dy = abs(y1 - y2);
	vector<pair<long long, long long>> ans = {{0, 0}, {1, 1}, {2, 0}, {3, 1}, {3, 3}, {4, 0}, {4, 2}};
	if (dy > dx) swap(dx, dy);
	for (auto p : ans)
		if (p.first == dx && p.second == dy) {
			cout << "Yes";
			return 0;
		}

	cout << "No";
	return 0;
}
