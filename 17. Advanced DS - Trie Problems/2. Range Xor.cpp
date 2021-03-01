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
	int max_xor_pair(int *arr,int x,int l,int r) {
		for(int i=l;i<=r;i++) {
			insert(arr[i]);
		}
		return max_xor_helper(x);
	}
};

int main() {
	int *arr = new int[100005];
	int i = 0;
	int q;
	cin>>q;
	while(q--) {
		int qt;
		cin>>qt;
		if(qt==0) {
			int num;
			cin>>num;
			arr[i++] = num;
		}
		else {
			int x,l,r;
			cin>>l>>r>>x;
			Trie t;
			cout<<(t.max_xor_pair(arr,x,l-1,r-1)^x)<<endl;
		}
	}
	delete [] arr;
	return 0;
}