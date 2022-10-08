#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l, r;
	cin >> l >> r;
	string s = "atcoder";
	cout << s.substr(l - 1, r - l + 1);
	return 0;
}
