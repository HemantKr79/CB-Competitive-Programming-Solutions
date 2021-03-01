#include <iostream>
#include<vector>
#include<list>
using namespace std;

#define inf 10000000

vector<vector<int> > floyd_warshall(int n,vector<list<pair<int,int> > > &l) {
    vector<vector<int> > dist(n+1,vector<int>(n+1,inf));
    for(int i=1;i<=n;i++) {
        dist[i][i] = 0;
        for(auto item : l[i]) {
            dist[i][item.first] = item.second;
        }
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist;
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<list<pair<int,int> > > l(v+1);
    int from,to,weight;
    for(int i=0;i<e;i++) {
        cin>>from>>to>>weight;
        l[from].push_back(make_pair(to,weight));
        l[to].push_back(make_pair(from,weight));
    }
    vector<vector<int> > dist = floyd_warshall(v,l);
    for(int i=1;i<=v;i++) {
        for(int j=1;j<=v;j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
