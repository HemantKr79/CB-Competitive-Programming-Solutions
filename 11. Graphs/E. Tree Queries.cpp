#include <iostream>
#include <vector>
using namespace std;

#define N 200005
vector<int> gr[N];
int tin[N],tout[N],dp[N];
int Par[N];
int timer;

void dfs(int cur,int par) {
    Par[cur] = par;
    tin[cur] = ++timer;
    dp[cur] = dp[par]+1;
    for(auto item : gr[cur]) {
        if(item!=par) {
            dfs(item,cur);
        }
    }
    tout[cur] = timer;
}

bool is_ancestor(int u,int v) {
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    timer = 0;
    tin[0] = 0;
    tout[0] = n+1;
    dfs(1,0);
    while(m--) {
        int k;
        cin>>k;
        int tmp,fart = 0;
        int *vertices = new int[k];
        for(int i=0;i<k;i++) {
            cin>>tmp;
            tmp = Par[tmp];
            vertices[i] = tmp;
            if(dp[tmp] > dp[fart]) {
                fart = tmp;
            }
        }
        string ans = "YES";
        for(int i=0;i<k;i++) {
            if(!is_ancestor(vertices[i],fart)) {
                ans = "NO";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
