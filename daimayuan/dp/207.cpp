#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	deque<int> dq;
	for (int i = 0; i < n; ++i) {
		while (dq.size() && a[dq.front()] < i + 1) dq.pop_front();
		while (dq.size() && b[dq.back()] <= b[i]) dq.pop_back();
		dq.push_back(i);
		cout << b[dq.front()] << "\n"; 
	}
	return 0;
}
