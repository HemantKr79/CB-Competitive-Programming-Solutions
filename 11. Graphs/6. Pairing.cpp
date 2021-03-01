#include<iostream>
#include<vector>
using namespace std;

#define int long long

struct dsu {
	vector<int> par;
	vector<int> sz;
	void init(int n) {
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}
	int get_superparent(int x) {
		if(par[x]==x) {
			return x;
		}
		int superparent_x = get_superparent(par[x]);
		par[x] = superparent_x;
		return par[x];
	}
	void unite(int x,int y) {
		int superparent_x = get_superparent(x);
		int superparent_y = get_superparent(y);
		if(superparent_x!=superparent_y) {
			par[superparent_x] = superparent_y;
			sz[superparent_y] += sz[superparent_x];
			sz[superparent_x] = 0;
		}
	}
};

int32_t main() {
	int n,m,x,y;
	cin>>n>>m;
	dsu g;
	g.init(n);
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		g.unite(x,y);
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += (n - g.sz[g.get_superparent(i)]);
	}
	cout<<ans/2;
	return 0;
}