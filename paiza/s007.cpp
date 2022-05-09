#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<long long> ct(26);
	string s;
	cin >> s;
	int n = s.size();

	stack<long long> stk;
	long long t = 0, pre = 1;
	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i])) t = t * 10 + s[i] - '0';
		else if (s[i] == '(') stk.push(t), pre *= t, t = 0;
		else if (isalpha(s[i])) ct[s[i] - 'a'] += 1ll * pre * (t == 0 ? 1 : t), t = 0;
		else pre /= stk.top(), stk.pop();
	}

	for (int i = 0; i < ct.size(); ++i)
		cout << (char)('a' + i) << " " << ct[i] << "\n";
	return 0;
}
