#include <bits/stdc++.h>

using namespace std;

long long x, y;

long long fr(long long r, long long nr);
long long fb(long long r, long long nr);

long long fr(long long r, long long nr) {
	if (nr >= 2)
		return fr(r, nr - 1) + fb(x * r, nr);
	return 0;
}

long long fb(long long b, long long nb) {
	if (nb >= 2)
		return fr(b, nb - 1) + fb(b * y, nb - 1);
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> x >> y;

	cout << fr(1, n);
	return 0;
}
