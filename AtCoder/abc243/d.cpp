#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	using ll = long long;
	ll n, x;
	string s;
	cin >> n >> x >> s;

	auto u = [](ll &x) { x /= 2; };	
	auto l = [](ll &x) { x = x * 2; };
	auto r = [](ll &x) { x = x * 2 + 1; };
	
	vector<char> stk;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'L' || s[i] == 'R')
			stk.emplace_back(s[i]);
		else {
			if (!stk.empty() && stk.back() != 'U') stk.pop_back();
			else stk.emplace_back(s[i]);
		}
	}

	for (int i = 0; i < stk.size(); ++i)
		if (stk[i] == 'U')
			u(x);
		else if (stk[i] == 'L')
			l(x);
		else r(x);

	cout << x << endl;
	return 0;
}

