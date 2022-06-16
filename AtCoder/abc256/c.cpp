#include <bits/stdc++.h>

using namespace std;

int f[4][4][31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> h(3), w(3);
	for (auto &x : h) cin >> x;
	for (auto &x : w) cin >> x;

	int ct = 0;
	int mat[3][3];
	auto check = [&]() {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (mat[i][j] <= 0 || mat[i][j] > w[j] - 2 || mat[i][j] > h[i] - 2) return false;
		for (int i = 0; i < 3; ++i) {
			int sum = 0;
			for (int j = 0; j < 3; ++j)
				sum += mat[i][j];
			if (sum != h[i]) return false;
			sum = 0;
			for (int j = 0; j < 3; ++j)
				sum += mat[j][i];
			if (sum != w[i]) return false;
		}
		return true;
	};

	for (int i = 1; i <= 31; ++i)
		for (int j = 1; j < w[1] - i; ++j)
			for (int k = 1; k < h[1] - i; ++k)
				for (int l = 1; l <= 30; ++l) {
					mat[1][1] = i;
					mat[0][1] = j;
					mat[1][2] = k;
					mat[0][2] = l;
					mat[0][0] = h[0] - mat[0][2] - mat[0][1];
					mat[2][2] = w[2] - mat[0][2] - mat[1][2];
					mat[1][0] = h[1] - mat[1][2] - mat[1][1];
					mat[2][1] = w[1] - mat[0][1] - mat[1][1];
					mat[2][0] = w[0] - mat[0][0] - mat[1][0];
					if (check()) ct += 1;
				}

	cout << ct;
	return 0;
}


