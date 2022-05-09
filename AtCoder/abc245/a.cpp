#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * 60 + b < c * 60 + d + 1) cout << "Takahashi";
	else cout << "Aoki";
	return 0;
}
