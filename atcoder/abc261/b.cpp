#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	for (auto &x : a) cin >> x;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i == j) continue;
			else {
				if (a[i][j] == 'W' && a[j][i] != 'L') {
					cout << "incorrect";
					return 0;
				} else if (a[i][j] == 'L' && a[j][i] != 'W') {
					cout << "incorrect";
					return 0;
				} else if (a[i][j] == 'D' && a[j][i] != 'D') {
					cout << "incorrect";
					return 0;
				}
			}

	cout << "correct";
	return 0;
}
