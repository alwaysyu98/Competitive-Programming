#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	long long a, s;
	while (n--) {
		cin >> a >> s;
		long long tmp = s - 2 * a;
		if (tmp < 0) {
			cout << "No\n";
			continue;
		}
		
		bool ok = true;

		for (int i = 0; tmp; ++i, tmp >>= 1, a >>= 1)
			if ((tmp & 1) == 1 && (a & 1) != 0) {
				ok = false;
				break;
			}
			
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
	
	return 0;
}