#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;

void dfs(int cur,vector<bool> &visited) {
    visited[cur] = true;
    for(auto nbr : adj[cur]) {
        if(!visited[nbr]) {
            dfs(nbr,visited);
        }
    }
}

int main() {
    int t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<int> strs[26];
        string tmp;
        for(int i=0;i<n;i++) {
            cin>>tmp;
            for(int j=0;j<tmp.size();j++) {
                strs[tmp[j]-'a'].push_back(i);
            }
        }
        adj.resize(n);
        for(int i=0;i<26;i++) {
            for(int j=0;j+1<strs[i].size();j++) {
                adj[strs[i][j]].push_back(strs[i][j+1]);
                adj[strs[i][j+1]].push_back(strs[i][j]);
            }
        }
        int ans = 0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,visited);
                ++ans;
            }
        }
        cout<<ans;
    }
    return 0;
}
