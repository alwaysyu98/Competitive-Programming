#include <bist/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int MOD = 998244353;

	int n, c, c0, c1, d0, d1, k;
	cin >> n >> c >> c0 >> c1 >> d0 >> d1;
	vector<int> b(n), s(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i] >> s[i];
	cin >> k;
	vector<int> pref(k);
	for (int i = 0; i < k; ++i)
		cin >> pref[i];


	return 0;
}
