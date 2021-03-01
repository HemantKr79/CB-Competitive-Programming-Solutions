#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define N 100005
vector<int> gr[N];

void dfs(int cur,int par,vector<bool> &visited) {
    cout<<cur<<" ";
    visited[cur] = true;
    for(auto nbr : gr[cur]) {
        if(visited[nbr]==false) {
            dfs(nbr,cur,visited);
        }
    }
}

int main() {
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    set<int> can;
    vector<int> v;
    v.reserve(n);
    v.push_back(1);
    visited[1] = true;
    while(v.size() < n) {
        int Prev = v.back();
        for(auto nbr : gr[Prev]) {
            if(visited[nbr]==false) {
                visited[nbr] = true;
                can.insert(nbr);
            }
        }
        v.push_back((*can.begin()));
        can.erase(can.begin());
    }
    for(auto item : v) {
        cout<<item<<" ";
    }
    return 0;
}
