#include<iostream>
using namespace std;

#define int long long

int n,k,q;
int *tree = new int[100001];
int *lazy = new int[100001];
int *a = new int[100001];
int *tmp = new int[100001];

void lets_do_it() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int f(int x) {
	int ans = 0;
	int index;
	for(int i=1;i<=k;i++) {
		index = (x + n - i)%n;
		++index;
		ans += tmp[index];
	}
	return ans;
}

void build_tree(int ss,int se,int index) {
	if(ss==se) {
		tree[index] = a[ss];
		return;
	}
	int m = (ss + se)/2;
	build_tree(ss,m,2*index+1);
	build_tree(m+1,se,2*index+2);
	tree[index] = tree[2*index+1] + tree[2*index+2];
}

void update(int ss,int se,int p,int change,int index) {
	if(lazy[index]!=0) {
		tree[index] += lazy[index];
		if(ss!=se) {
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(p<ss || p>se) {
		return;
	}
	if(p>=ss && p<=se) {
		tree[index] += change;
		if(ss!=se) {
			lazy[2*index+1] += change;
			lazy[2*index+2] += change;
		}
		return;
	}
	int m = (ss+se)/2;
	update(ss,m,p,change,2*index+1);
	update(m+1,se,p,change,2*index+2);	
}

int query(int ss,int se,int l,int r,int index) {
	if(lazy[index]!=0) {
		tree[index] += lazy[index];
		if(ss!=se) {
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}
		lazy[index] = 0;
	}
	if(r<ss || l>se) {
		return 0;
	}
	if(l<=ss && se<=r) {
		return tree[index];
	}
	int m = (ss+se)/2;
	int leftAns = query(ss,m,l,r,2*index+1);
	int rightAns = query(m+1,se,l,r,2*index+2);
	return leftAns + rightAns;
}

int32_t main() {
	lets_do_it();
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++) {
		cin>>tmp[i];
	}
	for(int i=1;i<=n;i++) {
		a[i] = f(i);
	}
	build_tree(1,n,1);
	cout<<"build_tree done"<<endl;
	while(q--) {
		int t;
		cin>>t;
		if(t==1) {
			int x,y,index;
			cin>>x>>y;
			int change = y - a[x];
			for(int i=1;i<=k;i++) {
				index = (x + n - i)%n;
				++index;
				update(1,n,index,change,1);
			}
		}
		else {
			int l,r;
			cin>>l>>r;
			cout<<query(1,n,l,r,1)<<endl;
		}
	}
	return 0;;
}