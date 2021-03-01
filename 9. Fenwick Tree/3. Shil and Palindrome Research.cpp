#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node {
	void setNode() {
		freq.resize(26);
		for(int i=0;i<26;i++) {
			freq[i] = 0;
		}
	}
	public:
	bool data;
	vector<int> freq;
	node(bool data) {
		this->data = data;
		setNode();
	}
	node() {
		setNode();
	}
};

void build_tree(vector<node> &tree,string &str,int ss,int se,int index) {
	if(ss==se) {
		tree[index].data = true;
		tree[index].freq[str[ss]-'a'] = 1;
		return;
	}
	int m = (ss+se)/2;
	build_tree(tree,str,ss,m,2*index);
	build_tree(tree,str,m+1,se,2*index+1);
	int cnt = 0;
	for(int i=0;i<26;i++) {
		tree[index].freq[i] = tree[2*index].freq[i] + tree[2*index+1].freq[i];
		if(tree[index].freq[i]%2!=0) {
			++cnt;
		}
	}
	if((se-ss+1)%2==0) {
		tree[index].data = cnt==0;
	}
	else {
		tree[index].data = cnt==1;
	}
}

void update_tree(vector<node> &tree,char from,char to,int ss,int se,int p,int index) {
	if(p<ss || p>se) {
		return;
	}
	if(ss==se && ss==p) {
		tree[index].freq[from - 'a'] -= 1;
		tree[index].freq[to -'a'] += 1;
		return;
	}
	int m = (ss+se)/2;
	update_tree(tree,from,to,ss,m,p,2*index);
	update_tree(tree,from,to,m+1,se,p,2*index+1);
	int cnt = 0;
	for(int i=0;i<26;i++) {
		tree[index].freq[i] = tree[2*index].freq[i] + tree[2*index+1].freq[i];
		if(tree[index].freq[i]%2!=0) {
			++cnt;
		}
	}
	if((se-ss+1)%2==0) {
		tree[index].data = cnt==0;
	}
	else {
		tree[index].data = cnt==1;
	}
}

node query(vector<node> &tree,int ss,int se,int l,int r,int index) {
	if(r<ss || l>se) {
		node newnode(true);
		return newnode;
	}
	if(l<=ss && r>=se) {
		return tree[index];
	}
	int m = (ss+se)/2;
	node leftAns = query(tree,ss,m,l,r,2*index);
	node rightAns = query(tree,m+1,se,l,r,2*index+1);
	for(int i=0;i<26;i++) {
		leftAns.freq[i] = leftAns.freq[i] + rightAns.freq[i];
	}
	return leftAns;
}

int32_t main() {
	int n,q;
	cin>>n>>q;
	string str;
	cin>>str;
	vector<node> tree(4*n+2,false);
	build_tree(tree,str,0,n-1,1);
	int qt,l;
	while(q--) {
		cin>>qt>>l;
		if(qt==1) {
			char to;
			cin>>to;
			update_tree(tree,str[l-1],to,0,n-1,l-1,1);
			str[l-1] = to;
		}
		else {
			int r;
			cin>>r;
			node nd = query(tree,0,n-1,l-1,r-1,1);
			int cnt = 0;
			for(int i=0;i<26;i++) {
				if(nd.freq[i]%2!=0) {
					++cnt;
				}
			}
			bool ans;
			if((r-l+1)%2==0) {
				ans = cnt==0;
			}
			else {
				ans = cnt==1;
			}
			if(ans) {
				cout<<"yes";
			}
			else {
				cout<<"no";
			}
			cout<<"\n";
		}
	}
	return 0;
}