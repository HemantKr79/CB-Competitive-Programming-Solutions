#include <bits/stdc++.h>
using namespace std;

int main() {
    int v,e,x,y,w;
    cin>>v>>e;
    vector<vector<pair<int,int> > > gr(v);
    for(int i=0;i<e;i++) {
        cin>>x>>y>>w;
        gr[x].push_back(make_pair(y,w));
        gr[y].push_back(make_pair(x,w));
    }
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater< pair<int,int> > > pq;
    vector<bool> vis(v,false);
    // in priority queue the first element is weight and the second element is the node
    pq.push(make_pair(0,0));
    int ans = 0;
    while(!pq.empty()) {
        pair<int,int> best = pq.top();
        pq.pop();
        int node = best.second;
        if(!vis[node]) {
            ans += best.first;
            vis[node] = true;
            for(auto nbr : gr[node]) {
                if(!vis[nbr.first]) {
                    pq.push(make_pair(nbr.second,nbr.first));
                }
            }
        }
    }
    cout<<ans;
    return 0;
}