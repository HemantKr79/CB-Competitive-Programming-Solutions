#include <iostream>
#include <vector>
using namespace std;

#define ll long long

struct DSU_algo {
    vector<ll> par;
    vector<ll> sz;
    void init(ll n) {
        par.resize(n);
        sz.resize(n);
        for(ll i=0;i<n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    ll get_superparent(ll x) {
        if(par[x]==x) {
            return x;
        }
        else {
            ll superparent = get_superparent(par[x]);
            par[x] = superparent;
            return par[x];
        }
    }
    void unite(ll x,ll y) {
        ll superparent_x = get_superparent(x);
        ll superparent_y = get_superparent(y);
        if(superparent_x!=superparent_y) {
            par[superparent_x] = superparent_y;
            sz[superparent_y] += sz[superparent_x];
            sz[superparent_x] = 0;
        }
    }
};

int main() {
    ll v,e;
    cin>>v>>e;
    DSU_algo g;
    g.init(v);
    for(ll i=0;i<e;i++) {
        ll x,y;
        cin>>x>>y;
        g.unite(x,y);
    }
    ll ans = 0;
    for(ll i=0;i<v;i++) {
        ans += (v-g.sz[g.get_superparent(i)]);
    }
    cout<<ans/2;
    return 0;
}
