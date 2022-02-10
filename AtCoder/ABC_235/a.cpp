#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n.size(); ++i) {
		for (int j = 0; j < n.size(); ++j) {
			ans += (n[j] - '0');
		}
		ans *= 10;
	}

	printf("%d", ans/10);
	return 0;
}
