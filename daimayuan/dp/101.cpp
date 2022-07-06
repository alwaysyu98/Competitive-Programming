#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	long long a = 1, b = 1;
	for (int i = 2; i <= n; ++i)
		a = a + b, b = a - b;
	cout << a << endl;
	return 0;
}
