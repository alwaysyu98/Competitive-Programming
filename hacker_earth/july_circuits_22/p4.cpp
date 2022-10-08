#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX_LEN = 100000;

class SegTree {
	int seg_tree[MAX_LEN << 2];
	int Lazy[MAX_LEN << 2];
	int arr[MAX_LEN];

	SegTree(int n, ) {
		memset(seg_tree, 0, sizeof(seg_tree));
		memset(Lazy, 0, sizeof(Lazy));
		memset(arr, 0, sizeof(arr));

		build(1, 1, n);
	}

	//从下往上更新 节点
	void push_up (int root) {
		seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //最小值改min
	}
	//从上向下更新，左右孩子
	void push_down (int root, int L, int R) {
		if(Lazy[root]){
			Lazy[root << 1] += Lazy [root];
			Lazy[root << 1 | 1] += Lazy[root];
			int mid = (L + R) >> 1;
			seg_tree[root << 1] +=  Lazy[root] * (mid - L + 1);
			seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
			Lazy[root] = 0;
		}
	}
	//建树
	//[L,R]就是对应arr数组里面的数
	void build (int root, int L, int R) {
		Lazy[root] = 0;
		if(L == R) {
			seg_tree[root] = arr[L];
			return ;
		}
		int mid = (L + R) >> 1;
		build(root << 1, L, mid);
		build(root << 1 | 1, mid + 1, R);
		push_up(root);
	}

	//区间查询
	//查找区间[LL,RR]的最大/小值
	int query (int root, int L, int R, int LL, int RR) {
		if (LL <= L && R <= RR) return seg_tree[root];
		push_down(root, L, R);     //每次访问都去检查Lazy 标记
		int Ans = 0;
		int mid = (L + R) >> 1;
		if(LL <= mid) Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //最小值改min
		if(RR > mid) Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //最小值改min
		return Ans;
	}
	//区间修改 +-某值
	//使得区间[LL,RR]的值都加上val
	void update_Interval(int root, int L, int R, int LL, int RR, int val){
		if (LL <= L && R <= RR) {
			Lazy[root] += val;
			seg_tree[root] += val * (R - L + 1);
			return ;
		}
		push_down(root, L, R);
		int mid = (L + R) >> 1;
		if (LL <= mid) update_Interval(root << 1, L, mid, LL, RR, val);
		if (RR > mid) update_Interval(root << 1 | 1, mid + 1, R, LL , RR, val);
		push_up(root);
	}
	//单点修改 可以改为某值，或者+-某值
	//把pos位置的值改成val
	void update(int root, int L, int R, int pos, int val) {
		if(L == R){
			seg_tree[root] = val;    //点直接变为某值
			return ;
		}
		int mid = (L + R) >> 1;
		if(pos <= mid) update(root << 1, L, mid, pos, val);
		else update(root << 1 | 1, mid + 1, R, pos, val);
		push_up(root);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;
		SegTree seg(n);

		vector<int> a(n);
		for (auto &x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			query
			seg.update_Interval(1, 1, n, a[i], a[i], 1);
		}
	}
	return 0;
}


