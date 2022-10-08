#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	stack<pair<char, int>> stk1, stk2;
	auto solve = [&](stack<pair<char, int>> &stk, string &s) {
		int n = s.size();
		for (int i = 0; i < n; ++i)
			if (stk.size() && stk.top().first == s[i])
				stk.top().second += 1;
			else stk.emplace(s[i], 1);
	};

	solve(stk1, a), solve(stk2, b);
	if (stk1.size() != stk2.size()) {
		cout << "No";
		return 0;
	} else {
		while (stk1.size() && stk2.size()) {
			auto [ch1, ct1] = stk1.top();
			auto [ch2, ct2] = stk2.top();
			stk1.pop();
			stk2.pop();
			if (ch1 != ch2 || ct1 > ct2) {
				cout << "No";
				return 0;
			} else if (ct1 == ct2) continue;
			else if (ct1 >= 2) continue;
			else {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
