#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;
	if (n > (1ll << 31) - 1 || n < -(1ll << 31))
		cout << "No";
	else cout << "Yes";

	return 0;
}
