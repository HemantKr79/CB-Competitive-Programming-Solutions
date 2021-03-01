#include<iostream>
using namespace std;

class Node {
	public:
	Node *left;
	Node *right;
	Node() {
		left = NULL;
		right = NULL;
	}
};

class Trie {
	public:
	Node *root;
	Trie() {
		root = new Node;
	}
	void insert(int num) {
		Node *tmp = root;
		for(int i=31;i>=0;i--) {
			int bit = (num>>i)&1;
			if(bit) {
				if(tmp->right==NULL) {
					tmp->right = new Node;
				}
				tmp = tmp->right;
			}
			else {
				if(tmp->left==NULL) {
					tmp->left = new Node;
				}
				tmp = tmp->left;
			}
		}
	}
	bool find(int num) {
		Node *tmp = root;
		for(int i=31;i>=0;i--) {
			int bit = (num>>i)&1;
			if(bit) {
				if(tmp->right) {
					tmp = tmp->right;
				}
				else {
					return false;
				}
			}
			else {
				if(tmp->left) {
					tmp = tmp->left;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
	int max_xor_helper(int value) {
		Node *tmp = root;
		int ans = 0;
		for(int i=31;i>=0;i--) {
			int bit = (value>>i)&1;
			if(bit) {
				if(tmp->left) {
					ans += (1<<i);
					tmp = tmp->left;
				}
				else {
					tmp = tmp->right;
				}
			}
			else {
				if(tmp->right) {
					ans += (1<<i);
					tmp = tmp->right;
				}
				else {
					tmp = tmp->left;
				}
			}
		}
		return ans;
	}
	int max_xor_pair(int *arr,int n) {
		int max_xor = 0;
		for(int i=0;i<n;i++) {
			insert(arr[i]);
			int cur_xor = max_xor_helper(arr[i]);
			max_xor = max(max_xor,cur_xor);
		}
		return max_xor;
	}
};

int solve(int *arr,int n) {
	int *cum = new int[n];
	int tmp = 0;
	for(int i=0;i<n;i++) {
		tmp = tmp^arr[i];
		cum[i] = tmp;
	}
	Trie t;
	int max_xor = 0;
	for(int i=0;i<n;i++) {
		max_xor = max(max_xor,cum[i]);
	}
	max_xor = max(max_xor,t.max_xor_pair(cum,n));
	int a,b;
	bool window = false;
	for(int i=0;i<n;i++) {
		tmp = max_xor^cum[i];
		if(t.find(tmp)) {
			for(int j=i+1;j<n;j++) {
				if(cum[j]==tmp) {
					a = i;
					b = j;
					window = true;
					break;
				}
			}
		}
		if(window) {
			break;
		}
	}
	cout<<a<<" "<<b<<endl;
	return max_xor;
}

int main() {
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	cout<<solve;
	return 0;
}