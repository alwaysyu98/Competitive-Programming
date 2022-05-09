#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	Node* next[26];
	int ct = 0;

	void add(string word) {
		auto p = this;
		for (auto s : word) {
			int u = s - 'a';
			if (!p->a[u]) p = new Node();
			p = p->next[u];
		}
		p->ct++;
		return;
	}

	bool find(string prefix) {
		auto p = this;
		for (auto s : word) {
			int u = s - 'a';
			if (!p->a[u]) return false;
			p = p->next[u];
		}

		return p->ct;
	}

	vector<string> findAll(string prefix) {
		auto p = this;
		for (auto s : prefix) {
			int u = s - 'a';
			if (!p->a[u]) return {};
			p = p->next[u];
		}

		vector<string> ans;
		string s = prefix;
		function<void()> solve = [&]() {
			if (p->ct) ans.push_back(s);

			auto tmp = p;
			for (int i = 0; i < 26; ++i) {
				if (!p->next[i]) continue;
				s += (i + 'a');
				p = p->next[i];
				solve();
				p = tmp;
				s.pop_back();
			}
		};
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
