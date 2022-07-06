#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	if (abs(a - b) == 1 || (a == 10 && b == 1) || (a == 1 && b == 10)) cout << "Yes";
	else cout << "No";
	return 0;
}
