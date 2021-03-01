#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct dsu {
    vector<int> par;
    void init(int n) {
        par.resize(n+2);
        for(int i=0;i<n+2;i++) {
            par[i] = i;
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
        }
    }
};

int main() {
    int n,q;
    cin>>n>>q;
    int l[q],r[q],c[q];
    int a[n+1];
    memset(a,0,sizeof(a));
    for(int i=0;i<q;i++) {
        cin>>l[i]>>r[i]>>c[i];
    }
    dsu g;
    g.init(n);
    for(int i=q-1;i>=0;i--) {
        int j = g.get_superparent(l[i]);
        while(j<=r[i]) {
            a[j] = c[i];
            g.unite(j,j+1);
            j = g.get_superparent(j);
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<a[i]<<endl;
    } 
    return 0;
}
