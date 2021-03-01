#include <iostream>
#include <vector>
using namespace std;

#define N 100005
vector<int> gr[N];
const int M = 22;
int Par[N][M],tin[N],tout[N];
int timer;

void cal_sparse_table(int cur,int par) {
    tin[cur] = ++timer;
    Par[cur][0] = par;
    for(int j=1;j<M;j++) {
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    }
    for(auto nbr : gr[cur]) {
        if(nbr!=par) {
            cal_sparse_table(nbr,cur);
        }
    }
    tout[cur] = timer;
}

bool is_ancestor(int u,int v) {
    //is u ancestor of v
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}
int lca_using_time(int u,int v) {
    if(is_ancestor(u,v)) {
        return u;
    }
    if(is_ancestor(v,u)) {
        return v;
    }
    for(int j=M-1;j>=0;j--) {
        if(!is_ancestor(Par[u][j],v)) {
            u = Par[u][j];
        }
    }
    return Par[u][0];
}

int main() {
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    timer = 0;
    tin[0] = 0;
    tout[0] = n+1;
    timer = 0;
    cal_sparse_table(1,0);
    cout<<lca_using_time(3,16)<<endl;
    cout<<lca_using_time(10,16)<<endl;
    cout<<lca_using_time(16,16)<<endl;
    return 0;
}
