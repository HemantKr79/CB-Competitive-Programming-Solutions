#include <iostream>
#include <list>
using namespace std;

#define ll long long

class Graph {
    public:
    ll V;
    list< pair<ll,ll> > *l;
    Graph(ll v) {
        V = v;
        l = new list< pair<ll,ll> >[v];
    }
    void addEdge(ll s,ll d,ll cost) {
        l[s].push_back(make_pair(d,cost));
        l[d].push_back(make_pair(s,cost));
    }
    ll dfs_helper(ll sv,bool visited[],ll count[],ll &ans) {
        visited[sv] = true;
        count[sv] = 1;
        for(auto neighbour : l[sv]) {
            ll neighbourVertex = neighbour.first;
            ll weight = neighbour.second;
            if(!visited[neighbourVertex]) {
                count[sv] += dfs_helper(neighbourVertex,visited,count,ans);
                ll x = count[neighbourVertex];
                ll y = V - x;
                ans += 2*min(x,y)*weight;
            }
        }
        return count[sv];
    }
    void dfs() {
        bool *visited = new bool[V];
        ll *count = new ll[V];
        for(ll i=0;i<V;i++) {
            visited[i] = false;
            count[i] = 0;
        }
        ll ans = 0;
        dfs_helper(0,visited,count,ans);
        cout<<ans;
        return;
    }
};

int main() {
    ll t;
    cin>>t;
    ll test = 1;
    while(t--) {
        ll n;
        cin>>n;
        Graph g(n);
        for(ll i=1;i<n;i++) {
            ll s,e,w;
            cin>>s>>e>>w;
            g.addEdge(s-1,e-1,w);
        }
        cout<<"Case #"<<test<<": ";
        g.dfs();
        test++;
        cout<<endl;
    }
    return 0;
}
