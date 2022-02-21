#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	stack<pair<int, int>> stk;
	int size = 0;
	for (int i = 0; i < n; ++i) {
		if (!stk.size()) {
			stk.emplace(a[i], 1);
			size++;
		} else {
			if (stk.top().first == a[i]) {
				stk.top().second += 1;
				size += 1;
				if (stk.top().first == stk.top().second) {
					size -= stk.top().first;
					stk.pop();
				}
			} else {
				stk.emplace(a[i], 1);
				size += 1;
			}
		}
		cout << size << "\n";
	}

	return 0;
}
