#include <bits/stdc++.h>

using namespace std;


// Follow-up
// 1. memory limited
// 2. getMedium

class MovingAverage {
public:
	const int expiredTime = 3000;
	queue<pair<int, int>> q;
	double sum;

	MovingAverage() : sum(0) {}

	int getNow() { return 0; }

	void record(int val) {
		q.emplace(val, getNow());
		sum += val;
	}
	// getMedium is seldom used
	double getMedium() {
		int n = q.size();
		vector<int> nums(n);
		queue<pair<int, int>> tq = q;
		for (int i = 0; i < n; ++i)
			nums[i] = tq.front().first, tq.pop();

		function<int(int, int, int)> findk = [&](int l, int r, int k) {
			if (l == r) return nums[l];
			int i = l - 1, j = r + 1, x = nums[l + r >> 1];
			while (i < j) {
				while (nums[++i] < x);
				while (nums[--j] > x);
				if (i < j) swap(nums[i], nums[j]);
			}
			if (k <= j) return findk(l, j, k);
			else return findk(j + 1, r, k);
		};

		if (n & 1) return findk(0, n - 1, n / 2);
		else return (findk(0, n - 1, n / 2 - 1) + findk(0, n - 1, n / 2)) / 2.0;
	}

	void popElements() {
		int t = getNow();
		while (q.size() && q.front().second < t - expiredTime) {
			sum -= q.front().first;
			q.pop();
		}
	}

	double getAvg() {
		popElements();
		return sum / q.size();
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MovingAverage ma;
	for (int i = 0; i < 4; ++i)
		ma.record(i * 3);

	return 0;
}
