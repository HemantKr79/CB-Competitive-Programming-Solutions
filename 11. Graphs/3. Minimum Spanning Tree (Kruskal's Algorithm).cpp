#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> par;
    void init(int n) {
        par.resize(n);
        for(int i=0;i<n;i++) {
            par[i] = i;
        }
    }
    int get_superparent(int x) {
        if(par[x]==x) {
            return x;
        }
        else {
            int superparent_x = get_superparent(par[x]);
            par[x] = superparent_x;
            return par[x];
        }
    }
    void unite(int superparent_x,int superparent_y) {
        if(superparent_x!=superparent_y) {
            par[superparent_x] = superparent_y;
        }
    }
};

int main() {
    int v,e,x,y,w;
    cin>>v>>e;
    dsu g;
    g.init(v);
    vector<vector<int> > edges(e);
    // edges[i][0] = weight, edges[i][1] = x, edges[i][2] = y
    for(int i=0;i<e;i++) {
        cin>>x>>y>>w;
        edges[i] = {w,x,y};
    }
    sort(edges.begin(),edges.end());
    int ans = 0;
    for(int i=0;i<e;i++) {
        w = edges[i][0];
        x = edges[i][1];
        y = edges[i][2];
        int superparent_x = g.get_superparent(x);
        int superparent_y = g.get_superparent(y);
        if(superparent_x!=superparent_y) {
            ans += w;
            g.unite(superparent_x,superparent_y);
        }
    }
    cout<<ans;
    return 0;
}