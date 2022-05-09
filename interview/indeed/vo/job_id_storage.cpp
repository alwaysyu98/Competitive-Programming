#include <bits/stdc++.h>

using namespace std;

// bitmap
// bloom filter
bitset<64> bs;

using pii = pair<int, int>;
vector<pii> intervals;

void merge_interval() {
	vector<pii> a;

	sort(a.begin(), a.end(), [&](const pii &a, const pii &b) { return a.first < b.first; });
	int n = a.size();
	if (n == 0) return;

	int l = a[0].first, r = a[0].second;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (r < a[i].first) ans.emplace_back(l, r), l = a[i].first, r = a[i].second;
		else r = max(r, a[i].second);
	}

	ans.emplace_back(l, r);
}

void expire(long id) {
	// add interval, basic model
	// O(n)

	// merge interval -> O(logn)
	bool ok = true;

	vector<int> ans;
	pair<int, int> newIntervals {id, id};
	for (int i = 0; i < intervals.size(); ++i) {
		if (intervals[i].first > newIntervals.second) {
			if (ok) ans.push_back(newIntervals), ok = false;
			ans.push_back(nums[i]);
		} else if (intervals[i].second < id) ans.push_back(newIntervals);
		else {
			newIntervals.first = min(newIntervals.first, nums[i].first);
			newIntervals.second = max(newIntervals.second, nums[i].second);
		}
	}
}

bool isExpired(long id) {
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	return 0;
}
