#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(m, vector<char> (n));
	using pii = pair<int, int>;
	pii s, e;
	for (int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 's')
				s = {i, j};
			else if (g[i][j] == 'g')
				e = {i, j};
		}

	vector<int> dir {-1, 0, 1, 0, -1};

	queue<pii> q;
	q.push(s);
	g[s.first][s.second] = '1';
	int step = 1;

	while (q.size()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			auto [x, y] = q.front();
			q.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = x + dir[j], ny = y + dir[j + 1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (g[nx][ny] == '1') continue;
				if (g[nx][ny] == 'g') {
					cout << step;
					return 0;
				}
				g[nx][ny] = '1';
				q.emplace(nx, ny);
			}
		}
		step++;
	}

	cout << "Fail";
	return 0;
}
