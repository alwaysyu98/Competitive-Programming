#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, r, c;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> r >> c;
		cout << "Case #" << i << ":\n";

		vector<vector<char>> s(2 * r + 1, vector<char> (2 * c + 1));

		for (int i = 0; i < 2 * r + 1; ++i)
			for (int j = 0; j < 2 * c + 1; ++j) {
				if (i % 2 == 0 && j % 2 == 0)
					s[i][j] = '+';
				else if (i % 2 != 0 && j % 2 == 0)
					s[i][j] = '|';
				else if (i % 2 == 0 && j % 2 != 0)
					s[i][j] = '-';
				else s[i][j] = '.';
			}

		s[0][0] = '.';
		s[0][1] = '.';
		s[1][0] = '.';

		for (int i = 0; i < s.size(); ++i, cout << "\n")
			for (int j = 0; j < s[0].size(); ++j)
				cout << s[i][j];
	}
	return 0;
}
