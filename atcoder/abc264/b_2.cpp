#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h1, h2, w1, w2;
	cin >> h1 >> w1;
	vector a(h1, vector<int> (w1));
	for (int i = 0; i < h1; ++i) for (int j = 0; j < w1; ++j) cin >> a[i][j];
	cin >> h2 >> w2;
	vector b(h2, vector<int> (w2));
	for (int i = 0; i < h2; ++i) for (int j = 0; j < w2; ++j) cin >> b[i][j];

	for (int i = 0; i < 1 << h1; ++i)
		for (int j = 0; j < 1 << w1; ++j) {
			vector<int> ta, tb;
			for (int k = 0; k < h1; ++k) if (i & (1 << k)) ta.push_back(k);
			for (int k = 0; k < w1; ++k) if (j & (1 << k)) tb.push_back(k);
			if (ta.size() != h2 || tb.size() != w2) continue;

			bool ok = true;
			for (int k = 0; k < h2; ++k)
				for (int l = 0; l < w2; ++l)
					if (a[ta[k]][tb[l]] == b[k][l]) continue;
					else ok = false;

			if (ok) {
				cout << "Yes";
				return 0;
			}
		}
	cout << "No";
	return 0;
}
