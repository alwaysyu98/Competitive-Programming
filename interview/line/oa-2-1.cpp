#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	double l, a, b, c, d;
	cin >> n >> l;
	vector<array<double, 4>> f(n);

	auto pair_hash = [&](const pair<double, double> x) {
		return hash<double> ()(x.first) ^ hash<double> ()(x.second);
	};

	unordered_map<pair<double, double>, int, decltype(pair_hash)> g(1000, pair_hash);
	int ct = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c >> d;
		if (!g.count({a, b})) g[{a, b}] = ct++;
		if (!g.count({c, d})) g[{c, d}] = ct++;
		f[i] = {a, b, c, d};
	}

	g[{0, 0}] = ct++;
	g[{100, 100}] = ct++;

	// disjoint set union
	class DSU {
		public:
			vector<int> a, sz;
			DSU(int n) : a(n), sz(n) {
				for (int i = 0; i < n; ++i) {
					a[i] = i;
					sz[i] = 1;
				}
			}

			int find(int x) {
				if (a[x] != x) a[x] = find(a[x]);
				return a[x];
			}

			void merge(int x, int y) {
				int rx = find(x), ry = find(y);
				if (rx == ry) return;
				if (sz[rx] > sz[ry]) swap(rx, ry);
				sz[ry] += sz[rx];
				a[rx] = ry;
			}
	};

	auto convertPairToInt = [&](double x, double y) {
		return g[{x, y}];
	};

	const double eps = 1e-6;
	// judge if two segments intersect
	auto judge = [&](double a1, double a2, double b1, double b2, double c1, double c2, double d1, double d2) {
		if (!(min(a1, b1) <= max(c1, d1) 
					&& min(c2, d2) <= max(a2, b2) 
					&& min(c1, d2) <= max(a1, b1)) 
				&& min(a2, b2) <= max(c2, d2)) return false;

		double u, v, w, z;
		u = (c1 - a1) * (b2 - a2) - (b1 - a1) * (c2 - a2);
		v = (d1 - a1) * (b2 - a2) - (b1 - a1) * (d2 - a2);
		w = (a1 - c1) * (d2 - c2) - (d1 - c1) * (a2 - c2);
		z = (b1 - c1) * (d2 - c2) - (d1 - c1) * (b2 - c2);
		return u * v < -eps && w * z < -eps;
	};

	DSU dsu(ct);

	// we assume that start point(0, 0), and end point(100, 100) 
	// are not in the same set at the beginning
	// these two points will always be possible to connect if there isn't a fence
	// from left/top wall to right/bottom wall

	// e.g. the following case
	//          TOP
	//         -----------
	//       |            |
	//       |            |
	//  left |------------| Right
	//         -----------
	//          Bottom
	// 
	// "fence" should from the wall to the wall. 
	// So, how to determine the fence is using union-find (disjoint set union)
	// we assume the start point(0, 0) means left/top, end-point(100, 100) means right/bottom
	// So if two segments intersect, we just add all these points into same set in our disjoint set union.
	// We only need to implement the "judge" function, to judge if two segments intersect.

	for (int i = 0; i < n; ++i) {
		double a = f[i][0], b = f[i][1], c = f[i][2], d = f[i][3];
		int id1 = convertPairToInt(a, b);
		int id2 = convertPairToInt(c, d);

		for (int j = 0; j < i; ++j) {
			double y1 = f[j][0], y2 = f[j][1], z1 = f[j][2], z2 = f[j][3];
			if (judge(a, b, c, d, y1, y2, z1, z2)) {
				dsu.merge(id1, dsu.find(convertPairToInt(y1, y2)));
			}
		}

		dsu.merge(id1, id2);
		if (fabs(a) <= eps || fabs(b - l) <= eps) dsu.merge(id1, dsu.find(convertPairToInt(0, 0)));
		if (fabs(b) <= eps || fabs(a - l) <= eps) dsu.merge(id1, dsu.find(convertPairToInt(100, 100)));
		if (fabs(c) <= eps || fabs(d - l) <= eps) dsu.merge(id2, dsu.find(convertPairToInt(0, 0)));
		if (fabs(d) <= eps || fabs(c - l) <= eps) dsu.merge(id2, dsu.find(convertPairToInt(100, 100)));

		if (dsu.find(convertPairToInt(0, 0)) == dsu.find(convertPairToInt(100, 100))) {
			cout << "NO\n" << i + 1;
			return 0;
		}
	}

	cout << "YES";
	return 0;
}

