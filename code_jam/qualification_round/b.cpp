#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	vector<int> c(3), m(3), y(3), k(3);
	const int SUM = 1e6;

	auto getmin = [&](vector<int> &nums) {
		int minn = INT_MAX;
		for (auto num : nums)
			minn = min(minn, num);
		return minn;
	};

	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		for (int j = 0; j < 3; ++j)
			cin >> c[j] >> m[j] >> y[j] >> k[j];
		int sum = SUM;
		vector<int> ans(4);
		ans[0] = min(sum, getmin(c)), sum -= ans[0];
		ans[1] = min(sum, getmin(m)), sum -= ans[1];
		ans[2] = min(sum, getmin(y)), sum -= ans[2];
		ans[3] = min(sum, getmin(k)), sum -= ans[3];

		if (sum > 0) cout << "IMPOSSIBLE";
		else for (int j = 0; j < 4; ++j)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}

