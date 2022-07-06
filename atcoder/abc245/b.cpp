#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;

	sort(a.begin(), a.end());
	if (a[0]) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i < n; ++i)
		if (a[i] - a[i - 1] == 0 || a[i] - a[i - 1] == 1) continue;
		else {
			cout << a[i - 1] + 1 << endl;
			return 0;
		}

	cout << a[n - 1] + 1 << endl; 
	return 0;
}

