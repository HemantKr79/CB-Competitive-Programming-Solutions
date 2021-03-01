#include <iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

bool bfs(int **redidualCapacity,int source,int sink,int *parent,int n) {
    bool *visisted = new bool[n];
    memset(visisted,0,sizeof(visisted));
    visisted[source] = true;
    bool foundAugmentedPath = false;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v=0;v<n;v++) {
            if(!visisted[v] && redidualCapacity[u][v]>0) {
                visisted[v] = true;
                parent[v] = u;
                q.push(v);
                if(v==sink) {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugmentedPaths(vector<vector<int> > augmentedPaths) {
    for(int i=0;i<augmentedPaths.size();i++) {
        for(int j=0;j<augmentedPaths[i].size()-1;j++) {
            cout<<augmentedPaths[i][j]<<"->";
        }
        cout<<augmentedPaths[i].back();
        cout<<endl;
    }
}

int edmond_karp(int **capacity,int source,int sink,int n) {
    int **redidualCapacity = new int*[n];
    for(int i=0;i<n;i++) {
        redidualCapacity[i] = new int[n];
        for(int j=0;j<n;j++) {
            redidualCapacity[i][j] = capacity[i][j];
        }
    }
    int *par = new int[n];
    int maxFlow = 0;
    vector<vector<int> > augmentedPaths;
    while(bfs(redidualCapacity,source,sink,par,n)) {
        vector<int> currentAugmentedPath;
        int flow = INT_MAX;
        int v = sink;
        while(v!=source) {
            currentAugmentedPath.push_back(v);
            int u = par[v];
            if(flow > redidualCapacity[u][v]) {
                flow = redidualCapacity[u][v];
            }
            v = u;
        }
        currentAugmentedPath.push_back(source);
        reverse(currentAugmentedPath.begin(),currentAugmentedPath.end());
        augmentedPaths.push_back(currentAugmentedPath);
        maxFlow += flow;
        v = sink;
        while(v!=source) {
            int u = par[v];
            redidualCapacity[u][v] -= flow;
            redidualCapacity[v][u] += flow;
            v = u;
        }
    }
    printAugmentedPaths(augmentedPaths);
    return maxFlow;
}

int main() {
    int v,e;
    cin>>v>>e;
    int **capacity = new int*[v];
    for(int i=0;i<v;i++) {
        capacity[i] = new int[v];
        for(int j=0;j<v;j++) {
            capacity[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        capacity[u][v] = c;
    }
    cout<<edmond_karp(capacity,0,1,v);
    return 0;
}
