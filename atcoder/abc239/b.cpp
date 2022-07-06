#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x;
	cin >> x;
	if (x >= 0)
		cout << x / 10;
	else {
		if (x % 10 == 0) 
			cout << x / 10;
		else cout << x / 10 - 1;
	}
	return 0;
}
