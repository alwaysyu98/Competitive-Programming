#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> a {0, 1, 0, 5};
	for (int i = 4; i <= 44; ++i) {
		a.push_back(a[i - 1] + a[i - 3]);
	}

	cout << a.back();
	return 0;
}
