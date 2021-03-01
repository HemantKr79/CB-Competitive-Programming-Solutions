#include <iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> gr[100005];
set<int> art_point;
vector<pair<int,int> > bridge;
int lowest[100005],discovery[100005],tmr;

void dfs(int cur,int par) {
    discovery[cur] = lowest[cur] = tmr++;
    int no_child = 0;
    for(auto child : gr[cur]) {
        if(discovery[child]==0) {
            dfs(child,cur);
            no_child++;
            lowest[cur] = min(lowest[cur],lowest[child]);
            if(par!=0 && lowest[child]>=discovery[cur]) {
                art_point.insert(cur);
            }
            if(lowest[child]>discovery[cur]) {
                bridge.push_back(make_pair(cur,child));
            }
        }
        else if(cur!=par) {
            lowest[cur] = min(lowest[cur],discovery[child]);
        }
    }
    if(par==0 && no_child>1) {
        art_point.insert(cur);
    }
}

int main() {
    int v,e;
    cin>>v>>e;
    int x,y;
    for(int i=0;i<e;i++) {
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    tmr = 1;
    dfs(1,0);
    for(auto item : art_point) {
        cout<<item<<" ";
    }
    return 0;
}
