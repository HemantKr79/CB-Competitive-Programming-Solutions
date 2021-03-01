

#include <iostream>
#include <vector>
using namespace std;

#define N 100005
#define M 22
vector<int> gr[N];
int Par[N][M];
int dep[N];

void cal_sparse_table(int cur,int par) {
    Par[cur][0] = par;
    for(int j=1;j<M;j++) {
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    }
    for(auto x : gr[cur]) {
        if(x!=par) {
            dep[x] = dep[cur] + 1;
            cal_sparse_table(x,cur);
        }
    }
}

int lca_using_depth(int u,int v) {
    if(u==v) {
        return u;
    }
    if(dep[u]<dep[v]) {
        swap(u,v);
    }
    int diff = dep[u] - dep[v];
    for(int i=M-1;i>=0;i--) {
        if((diff>>i)&1) {
            u = Par[u][i];
        }
    }
    //now u and v are on same depth
    if(u==v) {
        return u;
    }
    for(int i=M-1;i>=0;i--) {
        if(Par[u][i]!=Par[v][i]) {
            u = Par[u][i];
            v = Par[v][i];
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
    cal_sparse_table(1,0);
    cout<<lca_using_depth(3,16)<<endl;
    cout<<lca_using_depth(10,16)<<endl;
    cout<<lca_using_depth(16,16)<<endl;
    return 0;
}
