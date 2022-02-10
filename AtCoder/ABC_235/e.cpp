#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, Q;
	unordered_map<int, unordered_map<int, int>> g;
	
	cin >> N >> M >> Q;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b) continue;
		if (g[a].count(b) == 0) g[a][b] = c;
		else g[a][b] = min(c, g[a][b]);
		if (g[b].count(a) == 0) g[b][a] = c;
		else g[b][a] = min(c, g[b][a]);
	}

	while (Q--) {

	return 0;
}
