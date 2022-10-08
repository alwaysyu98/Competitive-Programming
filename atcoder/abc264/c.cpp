#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h1, w1, h2, w2;
	cin >> h1 >> w1;
	vector a(h1, vector<int> (w1));
	for (int i = 0; i < h1; ++i)
		for (int j = 0; j < w1; ++j)
			cin >> a[i][j];
	cin >> h2 >> w2;

	vector b(h2, vector<int> (w2));
	for (int i = 0; i < h2; ++i)
		for (int j = 0; j < w2; ++j)
			cin >> b[i][j];

	if (h1 < h2 || w1 < w2) cout << "No";
	else {
		vector<bool> r(h1), c(w1);
		function<bool(void)> check = [&]() {
			for (int i = 0, ii = 0; i < h1; ++i) {
				if (r[i]) continue;
				for (int j = 0, jj = 0; j < w1; ++j) {
					if(c[j]) continue;
					if (a[i][j] != b[ii][jj]) return false;
					jj ++;
				}
				ii ++;
			}
			return true;
		};

		int dh = h1 - h2, dw = w1 - w2;
		function<bool(int, int)> solve = [&](int i, int j) {
			if (i < h1) {
				r[i] = true;
				dh -= 1;
				bool t = solve(i + 1, j);
				dh += 1;
				r[i] = false;
				return t || solve(i + 1, j);
			} else if (j < w1) {
				c[j] = true;
				dw -= 1;
				bool t = solve(i, j + 1);
				dw += 1;
				c[j] = false;
				return t || solve(i, j + 1);
			} else if (dh == 0 && dw == 0) return check();
			else return false;
		};

		if (solve(0, 0)) cout << "Yes";
		else cout << "No";
	}
	return 0;
}
