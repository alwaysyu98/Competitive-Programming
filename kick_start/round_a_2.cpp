#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	string s;
	for (int tt = 1; tt <= t; ++tt) {
		cin >> s;

		int n = s.size(), sum = 0;
		for (int i = 0; i < n; ++i)
			sum += s[i] - '0';  
		int rem = sum % 9;
		if (rem) rem = 9 - rem;

		string ans = s + to_string(rem);
		if (rem == 0) ans = s.substr(0, 1) + '0' + s.substr(1);
		else {
			for (int i = 0; i < n; ++i) {
				if (s[i] - '0' > rem) {
					ans = s.substr(0, i) + to_string(rem) + s.substr(i);
					break;
				} else continue; 
			}	
		}

		cout << "Case #" << tt << ": " << ans << "\n";
	}
	
	return 0;
}
