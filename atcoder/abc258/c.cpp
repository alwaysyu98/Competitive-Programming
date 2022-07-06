#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;

	int ct = 0;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 1) ct = (ct + y) % n;
		else cout << s[(y - 1 + n - ct) % n] << '\n';
	}
	return 0;
}


