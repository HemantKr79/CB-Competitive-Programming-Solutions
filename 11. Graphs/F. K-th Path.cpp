#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define int long long
int inf = 1e18;

void lets_do_it() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int32_t main() {
	lets_do_it();
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	vector<pair<int,pair<int,int> > > edges;
	for(int i=0;i<m;i++) {
	    cin>>u>>v>>w;
	    edges.push_back(make_pair(w,make_pair(u,v)));
	}
	if(k>m) {
	    vector<vector<int> > mat(n+1,vector<int>(n+1,inf));
	    for(auto item : edges) {
	        w = item.first;
	        u = item.second.first;
	        v = item.second.second;
	        mat[u][v] = w;
	        mat[v][u] = w;
	    }
	    for(int k=1;k<=n;k++) {
    	    for(int i=1;i<=n;i++) {
    	       for(int j=1;j<=n;j++) {
    	           mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
    	       }
    	    }
    	}
	    vector<int> v;
	    v.reserve(n*n);
	    for(int i=1;i<=n;i++) {
	        for(int j=i+1;j<=n;j++) {
	            v.push_back(mat[i][j]);
	        }
	    }
	    sort(v.begin(),v.end());
	    cout<<v[k-1];
	}
	else {
	    map<int,int> mp;
	    sort(edges.begin(),edges.end());
	    for(int i=0;i<k;i++) {
	        u = edges[i].second.first;
	        v = edges[i].second.second;
	        mp[u] = 1;
	        mp[v] = 1;
	    }
	    int ls = 0;
	    for(auto it=mp.begin();it!=mp.end();++it) {
	        it->second = ++ls;
	    }
	    n = mp.size();
	    vector<vector<int> > mat(n+1,vector<int>(n+1,inf));
	    for(int i=1;i<=n;i++) {
	        mat[i][i] = 0;
	    }
	    for(int i=0;i<m;i++) {
	        u = edges[i].second.first;
	        v = edges[i].second.second;
	        w = edges[i].first;
	        if(mp.count(u) && mp.count(v)) {
	            int u1 = mp[u];
	            int u2 = mp[v];
	            mat[u1][u2] = mat[u2][u1] = w;
	        }
	    }
	    for(int k=1;k<=n;k++) {
    	    for(int i=1;i<=n;i++) {
    	       for(int j=1;j<=n;j++) {
    	           mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
    	       }
    	    }
    	 }
    	 vector<int> v;
    	 v.reserve(n*n);
    	 for(int i=1;i<=n;i++) {
    	   for(int j=1;j<=n;j++) {
    	       if(i>j) {
    	        v.push_back(mat[i][j]);
    	       }
    	   }
    	 }
    	 sort(v.begin(),v.end());
    	 cout<<v[k-1];
	}
	return 0;
}