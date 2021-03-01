#include<iostream>
#include<vector>
using namespace std;

#define int long long
#define mod 1000000007

vector<int> power(2000006,0);

void set_bits(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (power[se-ss+1] - 1 + mod)%mod;
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || l>se) {
		return;
	}
	if(l<=ss && r>=se) {
		tree[index] = (power[se-ss+1] - 1 + mod)%mod;
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = 1;
		}
		return;
	}
	int m = (ss+se)/2;
	set_bits(tree,lazy,ss,m,l,r,2*index);
	set_bits(tree,lazy,m+1,se,l,r,2*index+1);
	tree[index] = ( (power[se-m]*tree[2*index])%mod + tree[2*index+1])%mod;
}

void clear_bits(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (power[se-ss+1] - 1 + mod)%mod;
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || l>se) {
		return;
	}
	if(l<=ss && r>=se) {
		tree[index] = 0;
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = 0;
		}
		return;
	}
	int m = (ss+se)/2;
	clear_bits(tree,lazy,ss,m,l,r,2*index);
	clear_bits(tree,lazy,m+1,se,l,r,2*index+1);
	tree[index] = ( (power[se-m]*tree[2*index])%mod + tree[2*index+1])%mod;
}

int query(vector<int> &tree,vector<int> &lazy,int ss,int se,int l,int r,int index) {
	if(lazy[index]!=-1) {
		if(ss!=se) {
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		if(lazy[index]==1) {
			tree[index] = (power[se-ss+1] - 1 + mod)%mod;
		}
		else {
			tree[index] = 0;
		}
		lazy[index] = -1;
	}
	if(r<ss || l>se) {
		return 0;
	}
	if(l<=ss && r>=se) {
		return (tree[index]*power[r-se])%mod;
	}
	int m = (ss+se)/2;
	int leftAns = query(tree,lazy,ss,m,l,r,2*index);
	int rightAns = query(tree,lazy,m+1,se,l,r,2*index+1);
	return (leftAns+rightAns)%mod;
}

int32_t main() {
	int n,q;
	cin>>n>>q;
	vector<int> tree(4*n+2,0);
	vector<int> lazy(4*n+2,-1);
	power[0] = 1;
	for(int i=1;i<2000006;i++) {
		power[i] = 2*power[i-1];
		power[i] %= mod;
	}
	while(q--) {
		int qType,l,r;
		cin>>qType>>l>>r;
		if(qType==0) {
			clear_bits(tree,lazy,0,n-1,l,r,1);
		}
		else if(qType==1) {
			set_bits(tree,lazy,0,n-1,l,r,1);
		}
		else {
			cout<<query(tree,lazy,0,n-1,l,r,1)<<"\n";
		}
	}
	return 0;
}