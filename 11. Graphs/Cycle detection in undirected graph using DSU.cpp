#include <iostream>
#include <vector>
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
            int parent_x = get_superparent(par[x]);
            par[x] = parent_x;
            return par[x];
        }
    }
};

int main() {
    int v,e;
    cin>>v>>e;
    dsu g;
    g.init(v);
    bool isCyclic = false;
    for(int i=0;i<e;i++) {
        int x,y;
        cin>>x>>y;
        // to convert to 0 base indexing
        --x;
        --y;
        int superparent_x = g.get_superparent(x);
        int superparent_y = g.get_superparent(y);
        if(superparent_x!=superparent_y) {
            g.par[superparent_x] = superparent_y;
        }
        else {
            isCyclic = true;
        }
    }
    cout<<isCyclic;
    return 0;
}
