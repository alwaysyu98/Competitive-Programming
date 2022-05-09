#include <bits/stdc++.h>

using namespace std;

class Edge {
	Node2 *node;
	int cost;
	public Edge(Node2 *n, int cost) {
		this.node = n;
		this.cost = cost;
	}
};

class Node2 {
	vector<Edge> edges;
	public Node2() {}
};

int rootLeasfMinCost(Node2 *root) {
	unordered_map<Node2*, Edge> path;
	unordered_map<Node2*, int> g;
	vector<Edge> rese;

	function<int(Node2*)> solve = [&](Node2 *node) {
		if (g.count(node) == 1) return g[node];

		int res = INT_MAX;
		Edge tmpe;
		for (auto edge : node->edges) {
			if (edge->cost > res) continue;
			
			int tmp = solve(edge->node) + edge->cost;
			if (res > tmp) res = tmp, tmpe = edge;
		}

		// leaf
		if (res == INT_MAX) return g[node] = x;
		// node
		path[node] = tmpe;
		return g[node] = res;
	}

	int res = solve(root);

	auto tmp = root;
	while (tmp) rese.push_back(path[tmp]), tmp = path[tmp]->node;

	return res;
}

int rootLeafMinCost(Node2 *root) {
	unordered_map<Node2*, array<int, 2>> g;
	vector<Edge> resEdge;

	function<int(Node2*)> solve = [&](Node2 *node) {
		if (xx.count(node) == 1) return xx[node];
		int res = INT_MAX;
		Edge redge;
		for (auto edge : edges) {
			int tmp = solve(edge.node) + edge.cost;
			if (res > tmp) res = tmp, redge = edge;
		}

		if (res == INT_MAX) return 0 = xx[node];
		resEdge.push_back(redge);
		return xx[node] = res;
	};

	return solve(root);
}

int rootleafMinCost(Node2 *root) {
	using pni = pair<Node2*, int>;
	auto cmp = [&](const pni &a, const pni &b) { return a.second > b.second; };
	priority_queue<pni, vector<pni>, cmp> pq;

	unordered_map<Node2*, int> dis;
	unordered_mao<Node2*, bool> vis;

	pq.emplace(root, 0);
	dis[root] = true;
	while (pq.size()) {
		auto top = pq.top();
		pq.pop();

		for (Edge edge : top->edges)
			if (dis.count(

	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}

