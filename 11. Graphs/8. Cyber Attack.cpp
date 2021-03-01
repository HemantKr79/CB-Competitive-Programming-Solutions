#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

bool compare(vector<int> v1,vector<int> v2) {
	return v1[0]>v2[0];
}

struct dsu {
	vector<int> par;
	void init(int n) {
		par.resize(n+1);
		for(int i=0;i<=n;i++) {
			par[i] = i;
		}
	}
	int get_superparent(int x) {
		if(par[x]==x) {
			return x;
		}
		return par[x] = get_superparent(par[x]);
	}
	void unite(int x,int y) {
		int superparent_x = get_superparent(x);
		int superparent_y = get_superparent(y);
		if(superparent_x!=superparent_y) {
			par[superparent_x] = superparent_y;
		}
	}
};

int32_t main() {
	int n,m,s,x,y,c;
	cin>>n>>m>>s;
	vector<vector<int> > edges;
	edges.reserve(m);
	for(int i=0;i<m;i++) {
		cin>>x>>y>>c;
		edges.push_back({c,x,y});
	}
	sort(edges.begin(),edges.end(),compare);
	dsu g;
	g.init(n);
	int e = 0;
	vector<vector<int> > remaing_edges;
	for(auto item : edges) {
		int cost = item[0];
		x = item[1];
		y = item[2];
		int superparent_x = g.get_superparent(x);
		int superparent_y = g.get_superparent(y);
		if(superparent_x!=superparent_y) {
			g.unite(x,y);
		}
		else {
			remaing_edges.push_back(item);
		}
	}
	int nodeCount = 0;
	int cost = 0;
	sort(remaing_edges.begin(),remaing_edges.end());
	for(auto item : remaing_edges) {
		if(item[0] <= s) {
			s -= item[0];
			cost += item[0];
			nodeCount++;
		}
		else {
			break;
		}
	}
	cout<<nodeCount<<" "<<cost;
	return 0;
}