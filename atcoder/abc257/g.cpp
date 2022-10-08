#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;


	cout << (char)((x - 1) / n + 'A');
	return 0;
}

