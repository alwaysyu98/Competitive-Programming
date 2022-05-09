#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

vector<int> merge_k_sorted_streams(vector<ListNode*> streams, int k) {
	auto cmp = [](const ListNode *const &a, const ListNode *const &b) { return a->val > b->val; };
	priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

	for (auto &x : streams) if (x) pq.push(x);

	int last = INT_MIN, ct = 0;
	vector<int> ans;
	while (pq.size()) {
		auto top = pq.top();
		pq.pop();

		if (top->val == last) ct += 1;
		else {
			if (ct > k) ans.push_back(last);
			last = top->val;
			ct = 1;
		}

		top = top->next;
	}

	if (ct > k) ans.push_back(last);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	return 0;
}

