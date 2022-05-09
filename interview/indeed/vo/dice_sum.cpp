#include <bits/stdc++.h>

using namespace std;

double poss(int n, int target) {
	vector<int> f(target + 1);
	f[0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = target; j >= 0; --j) {
			f[j] = 0;
			for (int k = 1; k <= 6; ++k)
				if (j >= k)
					f[j] = f[j] + f[j - k];
		}

	return 1.0 * f[target] / pow(6, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, target;
	while (cin >> n >> target) {
		cout << poss(n, target) << "\n";
	}
	return 0;
}

