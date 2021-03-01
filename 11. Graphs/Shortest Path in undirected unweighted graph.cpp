#include <iostream>
#include <list>
#include <map>
#include <climits>
#include <queue>
using namespace std;

class Graph {
    int v;
    map<int,list<int> > l;
    void shortest_cycle_helper(int src,int &ans) {
        map<int,int> dist;
        for(auto item : l) {
            dist[item.first] = INT_MAX;
        }
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto nbr : l[node]) {
                if(dist[nbr]==INT_MAX) {
                    dist[nbr] = dist[node]+1;
                    q.push(nbr);
                }
                else if(dist[nbr]>=dist[node]) {
                    ans = min(ans,dist[nbr]+dist[node]+1);
                }
            }
        }
    }
    public:
    Graph(int v) {
        this->v = v;
    }
    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    int shortest_cycle() {
        int ans = v+1;
        for(auto item : l) {
            shortest_cycle_helper(item.first,ans);
        }
        if(ans==v+1) {
            return -1;
        }
        return ans;
    }
};

int main() {
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(5,3);
    cout<<g.shortest_cycle();
    return 0;
}
