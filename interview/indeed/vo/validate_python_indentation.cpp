#include <bits/stdc++.h>

using namespace std;

bool val(vector<string> codes) {
	int n = codes.size();
	stack<int> stk;
	auto trim = [&](string s) {
		int i = 0, n = s.size();
		while (i < n && s[i] == ' ') i++;
		return i;
	}

	stk.push(0);
	for (int i = 0; i < n; ++i) {
		int level = trim(codes[i]);
		if (!i && level) return false;

		if (i && codes[i - 1].back() == ':') {
			if (level <= stk.top()) return false;
		} else {
			while (stk.size() && stk.top() > level) stk.pop();
			if (stk.size() && stk.top() < level) return false;
		}
		stk.push(level);
	}
	return true;
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}

