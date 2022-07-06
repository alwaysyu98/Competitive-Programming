#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
	if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	for (int i = a; i <= b; ++i) {
		bool ok = true;
		for (int j = c; j <= d; ++j) {
			if (is_prime(i + j)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "Takahashi";
			return 0;
		}
	}
	cout << "Aoki" << endl;
	return 0;
}
