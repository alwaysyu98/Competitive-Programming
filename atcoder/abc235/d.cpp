#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, N;
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> N;
	queue<int> q;

	q.push(1);
	unordered_set<long long> dict;
	dict.insert(1);
	int ans = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			auto top = q.front();
			q.pop();
			dict.insert(top);
			if (top == N) {
				cout << ans;
				return 0;
			}

			// op 1
			long long tt = top * a;
			if (tt <= 10 * N && dict.count(tt) == 0) {
				q.push(tt);
				dict.insert(tt);
			}

			// op 2
			if (top < 10 || top % 10 == 0) continue;
			string tmp = to_string(top);
			tmp = tmp.back() + tmp;
			tmp.pop_back();
			long long b = stoll(tmp);
			if (b > 10 * N) continue;
			if (dict.count(b) == 0) {
				q.push(b);
				dict.insert(b);
			}
		}
		ans++;
	}
	printf("-1");
	return 0;
}
