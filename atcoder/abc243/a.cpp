#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int v, a, b, c;
	cin >> v >> a >> b >> c;
	v %= (a + b + c);

	if (v < a) cout << "F";
	else if (v < a + b) cout << "M";
	else cout << "T";

	return 0;
}
