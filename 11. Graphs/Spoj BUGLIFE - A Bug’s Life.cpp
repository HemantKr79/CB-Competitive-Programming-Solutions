#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
    int v;
    map<int,list<int> > l;
    bool isBipertite_helper(int node,int col,map<int,int> &visited) {
        visited[node] = col;
        for(auto child : l[node]) {
            if(visited[child]==0) {
                if(!isBipertite_helper(child,3-col,visited)) {
                    return false;
                }
            }
            else if(visited[child]==visited[node]) {
                return false;
            }
        }
        return true;
    }
    public:
    Graph(int v) {
        this->v = v;
    }
    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool isBipertite() {
        map<int,int> visited;
        for(auto item : l) {
            visited[item.first] = 0;
        }
        for(auto item : visited) {
            if(item.second==0) {
                if(!isBipertite_helper(item.first,1,visited)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int t;
    cin>>t;
    int cnt = 1;
    while(t--) {
        int v,e;
        cin>>v>>e;
        Graph g(v);
        int x,y;
        for(int i=0;i<e;i++) {
            cin>>x>>y;
            g.addEdge(x,y);
        }
        cout<<"Scenario #"<<cnt<<":"<<endl;
        if(g.isBipertite()) {
            cout<<"No suspicious bugs found!"<<endl;
        }
        else {
            cout<<"Suspicious bugs found!"<<endl;
        }
        cnt++;
    }
    return 0;
}
