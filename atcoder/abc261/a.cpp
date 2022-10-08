#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l1, l2, r1, r2;
	cin >> l1 >> r1 >> l2 >> r2;

	if (r2 < l1 || l2 > r1) cout << 0;
	else cout << min(r1, r2) - max(l1, l2);
	return 0;
}
