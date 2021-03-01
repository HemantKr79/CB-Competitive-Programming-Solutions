#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

const int N = 500005 * 22;

struct node {
	int lf, rt, cnt;
};

node trie[N];

int new_ptr;
int root[N];

int insert(int prev, int x) {
	int temp = new_ptr++;
	int cur = temp;
	trie[cur] = trie[prev];
	for (int bit = 20; bit >= 0; bit--) {
		int set = (x >> bit) & 1;
		if (set) {
			trie[cur].rt = new_ptr++;
			trie[trie[cur].rt] = trie[trie[prev].rt];
			trie[trie[cur].rt].cnt++;
			cur = trie[cur].rt;
			prev = trie[prev].rt;
		}
		else {
			trie[cur].lf = new_ptr++;
			trie[trie[cur].lf] = trie[trie[prev].lf];
			trie[trie[cur].lf].cnt++;
			cur = trie[cur].lf;
			prev = trie[prev].lf;
		}
	}
	return temp;
}

int maxxor(int prev, int cur, int x) {
	int y = 0;// number whose x^y is max
	for (int bit = 20; bit >= 0; bit--) {
		int set = (x >> bit) & 1;
		if (set) {
			if (trie[trie[cur].lf].cnt > trie[trie[prev].lf].cnt) {
				cur = trie[cur].lf;
				prev = trie[prev].lf;
			}
			else {
				cur = trie[cur].rt;
				prev = trie[prev].rt;
				y += (1 << bit);
			}
		}
		else {
			if (trie[trie[cur].rt].cnt > trie[trie[prev].rt].cnt) {
				cur = trie[cur].rt;
				prev = trie[prev].rt;
				y += (1 << bit);
			}
			else {
				cur = trie[cur].lf;
				prev = trie[prev].lf;
			}
		}
	}
	return y;
}

int lessthanequalto(int prev, int cur, int x) {
	int ans = 0;
	for (int bit = 20; bit >= 0; bit--) {
		int set = (x >> bit) & 1;
		if (set) {
			ans += trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt;
			cur = trie[cur].rt;
			prev = trie[prev].rt;
		}
		else {
			cur = trie[cur].lf;
			prev = trie[prev].lf;
		}
	}
	ans += trie[cur].cnt - trie[prev].cnt;
	return ans;
}

int kthsmallest(int prev, int cur, int k) {
	int ans = 0;
	for (int bit = 20; bit >= 0; bit--) {
		if (trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt >= k) {
			cur = trie[cur].lf;
			prev = trie[prev].lf;
		}
		else {
			k -= (trie[trie[cur].lf].cnt - trie[trie[prev].lf].cnt);
			cur = trie[cur].rt;
			prev = trie[prev].rt;
			ans += (1 << bit);
		}
	}
	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	root[0] = 0;
	trie[0].lf = trie[0].rt = trie[0].cnt = 0;
	new_ptr = 1;
	int n = 1;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 0) {
			// insert
			int x;
			cin >> x;
			root[n] = insert(root[n - 1], x);
			n++;
		}
		else if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			cout << maxxor(root[l - 1], root[r], x) << '\n';
		}
		else if (type == 2) {
			int k;
			cin >> k;
			n -= k;
		}
		else if (type == 3) {
			int l, r, x;
			cin >> l >> r >> x;
			cout << lessthanequalto(root[l - 1], root[r], x) << '\n';
		}
		else {
			int l, r, k;
			cin >> l >> r >> k;
			cout << kthsmallest(root[l - 1], root[r], k) << '\n';
		}
	}

}
