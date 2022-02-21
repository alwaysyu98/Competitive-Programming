#include <bits/stdc++.h>

using namespace std;

int f[1020], bf[1020];

// 其实直接贪心+时间序列模拟即可
// 用f[i]表示花了i的事件能跑多远
// 先处理出只用魔法的，之后就可以f[i] = max(f[i], f[i - 1] + 17)了
// 如果不处理的话，hack 数据 6 54 3，数据会输出错误的结果
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, s, t;
	cin >> m >> s >> t;

	int flag = t + 1;
	memset(f, -1, sizeof(f));
	f[m] = 0;
	for (int i = 1; i <= t; ++i) {
		memcpy(bf, f, sizeof(bf));
		for (int j = 0; j <= m + 10; ++j) {
			f[j + 4] = max(f[j + 4], bf[j]);
			if (j >= 10 && bf[j] >= 0)
				f[j - 10] = max(f[j - 10], bf[j] + 60);
			if (bf[j] >= 0)
				f[j] = max(f[j], bf[j] + 17);
			if (f[j + 4] >= s || (j >= 10 && f[j - 10] >= s) || f[j] >= s)
				flag = min(flag, i);
		}
	}

	int ans = 0;
	for (int i = 0; i <= m; ++i)
		ans = max(ans, f[i]);
	if (flag != t + 1) cout << "Yes\n" << flag;
	else cout << "No\n" << ans;
	return 0;
}
