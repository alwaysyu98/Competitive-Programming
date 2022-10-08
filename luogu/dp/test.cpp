#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//auto myhash = [&](const pair<string, int> &a) {
	//    return hash<string> ()(a.first) ^ hash<int> ()(a.second);
	//};
	struct myhash {
		bool operator()(const pair<string, int> &a) const {
			return hash<string> ()(a.first) ^ hash<int> ()(a.second);
		}
	};
	//unordered_map<pair<string, int>, int, decltype(myhash)> g(0, myhash);
	unordered_map<pair<string, int>, int, myhash> g;
	g[make_pair("1", 2)] = 1;
	cout << g[{"1", 2}] << endl;
	return 0;
}
