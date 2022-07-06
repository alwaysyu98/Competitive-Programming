#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, now = -1; 
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!i || a[i] > a[i - 1]) now++;
		else break;
	}

	printf("%d", a[now]);
	return 0;
}
