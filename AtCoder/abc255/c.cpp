#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x, a, d, n;
	cin >> x >> a >> d >> n;

	long long a1 = a, an = a + d * (n - 1);
	if (d < 0) swap(a1, an), d = -d;

	if (x <= a1 || x >= an) cout << min(abs(x - an), abs(x - a1));
	else {
		long long delta = x - a1;
		long long ct = delta / d;
		long long ad = a1 + ct * d, ad1 = ad + d;
		cout << min(abs(x - ad), abs(x - ad1)); 
	}
	return 0;
}

