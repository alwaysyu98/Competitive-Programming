#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		char[] chars = new char[5];
		int len;
		Node next;
		Node() : next(nullptr), len(0) {}
};

class LinkedList {
	Node *head;
	int tot;

	char get(int index) {
		int ct = 0;
		if (index < 0 || index >= tot) return ' ';
		Node *cur = head;
		while (cur && ct <= index) {
			if (index - ct >= cur->len) ct += cur->len;
			else return cur->chars[index - ct];
			cur = cur->next;
		}
		return ' ';
	}

	void insert(char ch, int index) {
		if (index > tot) return;
		tot += 1;
		Node *cur = head;
		while (cur && index >= 0) {
			if (index >= cur->len) index -= cur->len;
			else {
				if (cur->len == 5) {
					Node tmp = new Node();
					tmp->next = cur->next;
					cur->next = tmp;
					tmp->chars[0] = cur->chars[4];
					tmp->len = 1;
					tmp->chars[4] = ch;
					cur.len -= 1;
				}
				cur.len += 1;
				for (int i = cur->len - 1; i > index; --i)
					cur->chars[i] = cur->chars[i - 1];
				cur.chars[i] = ch;
				break;
			}
			cur = cur->next;
		}

		if (!cur) {
			Node tmp = new Node();
			tmp.chars[0] = ch;
			tmp.len = 1;

		}
	}

	void delete(int index) {
		if (index < 0 || index >= tot) return;

		Node *pre = new Node(), *cur = head;
		pre->next = head;

		while (cur && index >= 0) {
			if (index >= cur->len) index -= cur->len;
			else {
				if (cur->len == 1) pre->next = cur->next, delete(cur);
				else {
				}
			}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	return 0;
}
