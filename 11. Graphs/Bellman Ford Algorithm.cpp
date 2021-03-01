#include <iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> bellman_ford(int src,int n,vector<vector<int> > &edges) {
    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;
    int from,to,weight;
    for(int i=0;i<n-1;i++) {
        for(auto x : edges) {
            from = x[0];
            to = x[1];
            weight = x[2];
            if(dist[from]!=INT_MAX && dist[to]>dist[from]+weight) {
                dist[to] = dist[from] + weight;
            }
        }
    }
    for(auto x : edges) {
        from = x[0];
        to = x[1];
        weight = x[2];
        if(dist[from]!=INT_MAX && dist[to]>dist[from]+weight) {
            cout<<"Negative weight cycle";
            exit(0);
        }
    }
    return dist;
}

int main() {
    int v,e;
    cin>>v>>e;
    int from,to,weight;
    vector<vector<int> > edges;
    for(int i=0;i<e;i++) {
        cin>>from>>to>>weight;
        edges.push_back({from,to,weight});
    }
    vector<int> dist = bellman_ford(1,v,edges);
    for(int i=1;i<=v;i++) {
        cout<<"Distance of "<<i<<" from source is "<<dist[i]<<endl;
    }
    return 0;
}
