#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	int a = 21 + k / 60, b = k % 60;
	cout << a << ":";
	if (b < 10) cout << "0" << b;
	else cout << b;
	return 0;
}
