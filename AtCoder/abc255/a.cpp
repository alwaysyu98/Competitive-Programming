#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;
	int a[2][2];
	cin >> a[0][0] >> a[0][1];
	cin >> a[1][0] >> a[1][1];

	cout << a[r - 1][c - 1];
	return 0;
}
