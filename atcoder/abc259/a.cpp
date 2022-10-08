#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, x, t, d;
	cin >> n >> m >> x >> t >> d;

	if (m >= x) cout << t;
	else if (m < x) cout << t - (x - m) * d;
	return 0;
}
