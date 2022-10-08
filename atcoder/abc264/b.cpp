#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;

	int a = r, b = 16 - r;
	if (b <= a) swap(a, b);
	if (r % 2 == 1) {
		if (c >= a && c <= b) cout << "black";
		else if (c % 2 == 1) cout << "black";
		else cout << "white";
	} else {
		if (c >= a && c <= b) cout << "white";
		else if (c % 2 == 1) cout << "black";
		else cout << "white";
	}
	return 0;
}
