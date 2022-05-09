#include <bits/stdc++.h>

using namespace std;

//test case
//7 12
//1p3acres is a good place to communicate

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> words(n);
	for (auto &s : words)
		cin >> s;

	vector<string> ans;
	string s = "";
	for (int i = 0; i < n; ++i)
		if (!s.size())
			s = words[i];
		else if (s.size() + words[i].size() + 1 <= m) 
			s = s + "-" + words[i];
		else 
			ans.push_back(s), s = words[i];

	if (s.size()) ans.push_back(s);

	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;
	return 0;
}
