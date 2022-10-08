#include <bits/stdc++.h>

using namespace std;

struct Trash {
	int t, f, h;
};

// state-compression dp can also solve this

int main() {
	int D, G;
	cin >> D >> G;
	vector<Trash> ts(G);
	for (int i = 0; i < G; ++i)
		cin >> ts[i].t >> ts[i].f >> ts[i].h; 

	sort(ts.begin(), ts.end(), [&](const Trash &a, const Trash &b) { return a.t < b.t; });

	vector<int> f(D + 1);
	f[0] = 10;
	for (int i = 0; i < G; ++i)
		for (int j = D; j >= 0; --j)
			if (f[j] >= ts[i].t) {
				if (j + ts[i].h >= D) {
					cout << ts[i].t << "\n";
					return 0;
				}
				f[j + ts[i].h] = max(f[j + ts[i].h], f[j]);
				f[j] = max(f[j], f[j] + ts[i].f);
			}

	cout << f[0] << "\n";
	return 0;
}

