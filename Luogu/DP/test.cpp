#include <bits/stdc++.h>

using namespace std;

bool cmp (const int &x, const int &y) {
	return x < y;
};

int main() {
	class myhash {
		public:
			size_t operator()(const pair<int, int> &x) const {
				return hash<int>()(x.first) ^ hash<int>()(x.second);
			}
	};
	unordered_map<pair<int, int>, int, myhash> g;
	vector<int> a {3, 2,5, 6, 1, 23};

	sort(a.begin(), a.end(), cmp);
	g[{0, 0}] = 1;
	return 0;
}
