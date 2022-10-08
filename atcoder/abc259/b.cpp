#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, d;
	cin >> a >> b >> d;

	double t = 1.0 * d / 180.0 * M_PI;
	double cosx = cos(t), sinx = sin(t);

	cout << setiosflags(ios::fixed);
	cout << setprecision(7) << a * cosx - b * sinx << ' ' << b * cosx + a * sinx;
	return 0;
}

