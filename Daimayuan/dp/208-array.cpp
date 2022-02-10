#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, v, w, l;
	cin >> n >> m;
	
	vector<int> f(m + 1);
	int ndq[10001][2], qq = 0, tt = -1;
	for (int i = 0; i < n; ++i) {
		cin >> v >> w >> l;
		for (int j = 0; j < v; ++j) {
			qq = 0, tt = -1;
			for (int q = j, x = 0; q <= m; q += v, x++) {
				int e = f[q] - x * w;
				while (qq <= tt && ndq[qq][0] < x - l) qq++; 
				while (qq <= tt && ndq[tt][1] <= e) tt--; 
				++tt, ndq[tt][0] = x, ndq[tt][1] = e;
				f[q] = ndq[qq][1] + x * w;
			}
		}
	}

	cout << f[m] << "\n";
	return 0;
}
