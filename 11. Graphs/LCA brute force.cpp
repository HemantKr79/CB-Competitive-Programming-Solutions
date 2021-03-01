#include <iostream>
#include <vector>
using namespace std;

#define N 100001
vector<int> gr[N];
int Par[N],dep[N];

void dfs(int cur,int par) {
    Par[cur] = par;
    for(auto x : gr[cur]) {
        if(x!=par) {
        	dep[x] = dep[cur] + 1;
            dfs(x,cur);
        }
    }
}

int lca_brute(int u,int v) {
    if(u==v) {
        return v;
    }
    if(dep[u]<dep[v]) {
        swap(u,v);
    }
    while(dep[u]!=dep[v]) {
        u = Par[u];
    }
    while(u!=v) {
        u = Par[u];
        v = Par[v];
    }
    return u;
}

int main() {
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,0);
    cout<<lca_brute(3,16)<<endl;
    cout<<lca_brute(10,16)<<endl;
    cout<<lca_brute(16,16);
    return 0;
}