#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int oa, ob, x, y, r, l;
	double t;
	cin >> oa >> ob >> x >> y >> r >> t >> l;
	t = t * 1.0 / 180 * M_PI;
	int a = oa - 2 * r, b = ob - 2 * r;

	double dx, dy;
	//if (t >= 0 && t <= 90) dx = abs(x - r), dy = abs(y - r);
	//else if (t > 90 && t <= 180) dx = abs(a - x + r), dy = abs(y - r);
	//else if (t > 180 && t <= 270) dx = abs(a - x + r), dy = abs(b - y + r);
	//else dx = abs(x - r), dy = abs(b - y + r);

	if (t >= 0 && t <= 90) dx = abs(a - x + r), dy = abs(b - y + r);
	else if (t > 90 && t <= 180) dx = abs(x - r), dy = abs(b - y + r);
	else if (t > 180 && t <= 270) dx = abs(x - r), dy = abs(y - r);
	else dx = abs(a - x + r), dy = abs(y - r);

	int n = 0, m = 0;
	double ansx, ansy;
	double tarx = abs(cos(t) * l) - dx, tary = abs(sin(t) * l) - dy;
	if (tarx <= 0) ansx = x + tarx + dx; 
	else {
		n++;
		n += tarx / a;
		double resx = tarx - n * a;
		if (resx < 0) resx += a, n ++;
		n %= 2;

		if (n == 1) ansx = a - resx + r;
		else ansx = resx + r;
	}

	if (tary <= 0) ansy = y + tary + dy;
	else {
		m++;
		m += tary / b;
		double resy = tary - m * b;
		if (resy < 0) resy += b, m--;
		m %= 2;
		
		if (m == 1) ansy = b - resy + r;
		else ansy = resy + r;
	}

	cout << fixed << setprecision(12) << ansx << " " << ansy;
	return 0;
}
