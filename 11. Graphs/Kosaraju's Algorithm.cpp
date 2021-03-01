#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define N 100005

vector<int> gr[N]; //Adjancy list for original graph
vector<int> grr[N]; //Adjancy list for reverse graph
vector<int> ordering; // ordering stores the order of dfs traversal
int component[N]; // component[i] stores the color of i th component

void dfs(int node,bool *visited) {
    visited[node] = true;
    for(auto nbr : gr[node]) {
        if(!visited[nbr]) {
            dfs(nbr,visited);
        }
    }
    ordering.push_back(node);
}

void dfs_reverse(int node,bool *visited,int col) {
    visited[node] = true;
    component[node] = col;
    for(auto nbr : grr[node]) {
        if(!visited[nbr]) {
            dfs_reverse(nbr,visited,col);
        }
    }
}

int main() {
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++) {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    bool *visited = new bool[v+1];
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=v;i++) {
        if(!visited[i]) {
            dfs(i,visited);
        }
    }
    memset(visited,false,sizeof(visited));
    cout<<"ordering: ";
    for(auto item : ordering) {
        cout<<item<<" ";
    }
    cout<<endl;
    int col = 1;
    for(int i=v;i>=1;i--) {
        if(!visited[ordering[i]]) {
            dfs_reverse(ordering[i],visited,col);
            ++col;
        }
    }
    for(int i=1;i<=v;i++) {
        cout<<i<<" -> "<<component[i]<<endl;
    }
    return 0;
}
