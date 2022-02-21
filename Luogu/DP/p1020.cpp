#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> a;
	int x;
	while (cin >> x)
		a.push_back(x);

	int n = a.size(), k = 0;
	vector<int> t(n + 1);	
	t[0] = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int l = 0, r = k;
		while (l < r) {
			int mid = l + (r - l + 1 >> 1);
			if (t[mid] >= a[i]) l = mid;
			else r = mid - 1;
		}
		t[l + 1] = a[i];
		k = max(k, l + 1);
	}
	cout << k << "\n";

	k = 0;
	t.resize(n + 1, 0);	
	t[0] = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int l = 0, r = k;
		while (l < r) {
			int mid = l + (r - l + 1 >> 1);
			if (t[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		t[l + 1] = a[i];
		k = max(k, l + 1);
	}

	cout << k << endl;
	return 0;
}
