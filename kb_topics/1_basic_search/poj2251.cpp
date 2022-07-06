#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s[100][100];
vector<vector<int> > dirs {{0, 0, -1}, {0, 0, 1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

	while (true) {
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		string ss;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j)
				cin >> s[i][j];

		queue<array<int, 3>> q;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j < r; ++j)
				for (int k = 0; k < c; ++k)
					if (s[i][j][k] == 'S')
						q.push({i, j, k});

		function<int(void)> bfs = [&]() {
			int step = 1;
			while (q.size()) {
				int size = q.size();
				for (int i = 0; i < size; ++i) {
					auto top = q.front();
					q.pop();
					int x = top.at(0), y = top.at(1), z = top.at(2);
					for (auto &dir : dirs) {
						int nx = x + dir[0], ny = y + dir[1], nz = z + dir[2];
						if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
						if (s[nx][ny][nz] == '#') continue;
						if (s[nx][ny][nz] == 'E') return step;
						s[nx][ny][nz] = '#';
						q.push({nx, ny, nz});
					}
				}
				step++;
			}

			return INF;
		};

		int ans = bfs();
		if (ans == INF) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
	return 0;
}