#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	long long x, k;
	cin >> n >> q;
	
	unordered_map<long long, vector<int>> dict;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		dict[x].push_back(i);
	}

	while (q--) {
		cin >> x >> k;
		if (dict[x].size() < k ) printf("-1\n");
		else printf("%d\n", dict[x][k - 1] + 1);
	}
	return 0;
}
