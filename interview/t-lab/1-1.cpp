#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	vector<pair<char, int>> g {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
		{'X', 10}, {'V', 5}, {'I', 1}};
	auto get = [&](int x) {
		int t = 0;

		for (auto [ch, v] : g) {
			if (x 
			if (x >= v) {
				int tmp = x / v;
				if (tmp == 4 && (ch == 'I' || ch == 'X' || ch == 'C')) tmp = 2;
				t += tmp;
				x %= v;
			}
		}

		return t;
	};

	int ct = 0;
	for (int i = 1; i <= 1000; ++i) {
		if (get(i) == 9) ct += i;
	}
	cout << ct;

	return 0;
}

