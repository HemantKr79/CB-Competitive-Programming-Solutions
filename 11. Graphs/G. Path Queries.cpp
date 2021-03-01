#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
 
#define int long long
 
void lets_do_it() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
 
struct dsu {
    vector<int> Par;
    vector<int> sz;
    void init(int n) {
        Par.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<=n;i++) {
            Par[i] = i;
            sz[i] = 1;
        }
    }
    int get_superparent(int u) {
        if(Par[u]==u) {
            return u;
        }
        int superparent = get_superparent(Par[u]);
        Par[u] = superparent;
        return Par[u];
    }
    int unite(int u,int v) {
        int superparent_u = get_superparent(u);
        int superparent_v = get_superparent(v);
        Par[superparent_u] = Par[superparent_v];
        int ans = sz[superparent_u]*sz[superparent_v];
        sz[superparent_v] += sz[superparent_u];
        sz[superparent_u] = 0;
        return ans;
    }
};
 
int32_t main() {
	lets_do_it();
	int n,m,u,v,w;
	cin>>n>>m;
	vector<pair<int,pair<int,int> > > edges;
	edges.reserve(n-1);
	for(int i=0;i<n-1;i++) {
	    cin>>u>>v>>w;
	    edges.push_back(make_pair(w,make_pair(u,v)));
	}
	sort(edges.begin(),edges.end());
	dsu g;
	g.init(n);
	map<int,int> cnt;
	for(int i=0;i<n-1;i++) {
	    u = edges[i].second.first;
	    v = edges[i].second.second;
	    w = edges[i].first;
	    cnt[w] += g.unite(u,v);
	}
	int prev_val = 0;
	vector<pair<int,int> > query;
	query.reserve(cnt.size());
	for(auto item : cnt) {
	    prev_val += item.second;
	    query.push_back(make_pair(item.first,prev_val));
	    //cout<<"("<<item.first<<","<<item.second<<") ";
	}
	while(m--) {
	    int q;
	    cin>>q;
	    pair<int,int> tmp = make_pair(q,LLONG_MAX);
	    auto it = upper_bound(query.begin(),query.end(),tmp);
	    if(it==query.begin()) {
	        cout<<0<<" ";
	    }
	    else {
	        --it;
	        cout<<it->second<<" ";
	    }
	}
	return 0;
}