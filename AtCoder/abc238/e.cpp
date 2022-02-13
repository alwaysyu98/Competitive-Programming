#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	vector<int> p, size;
	UF(int n) : p(n + 1), size(n + 1) {
		for (int i = 0; i <= n; ++i)
			p[i] = i, size[i] = 1;
	}

	int find(int x) {
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	void unite(int a, int b) {
		int ra = find(a), rb = find(b);
		if (ra == rb) return;
		if (size[ra] >= size[rb]) swap(ra, rb);
		p[ra] = rb;
		size[rb] += size[ra];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q, l, r;
	cin >> n >> q;
	UF uf(n);
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		uf.unite(l - 1, r);
	}

	int ra = uf.find(0), rb = uf.find(n);
	if (ra == rb) cout << "Yes";
	else cout << "No";

	return 0;
}