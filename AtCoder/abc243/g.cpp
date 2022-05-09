#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int N = 1e5 + 10;

	clock_t start, end;
	start = clock();
	//vector<array<int, 26>> vector_a(N);
	vector<array<int, 26>> vector_a(N);
	end = clock();
	cout << end - start << "\n";
	
	start = clock();
	int array_a[N][26];
	memset(array_a, 0, sizeof(array_a));
	end = clock();
	cout << end - start << "\n";

	array<int, 26> x;
	for (int i = 0; i < 26; ++i)
		x[i] = 2;

	return 0;
}
