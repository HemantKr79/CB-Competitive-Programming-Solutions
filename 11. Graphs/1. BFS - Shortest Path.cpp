#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

template<typename T>
class Graph {
    int v;
    map<T,list<T> > l;
    public:
    Graph(int v) {
        this->v = v;
        list<int> tmp;
        for(int i=1;i<=v;i++) {
            l.insert(make_pair(i,tmp));
        }
    }
    void addEdge(T x,T y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print_adjacency_list() {
        for(pair<T,list<T> > p : l) {
            cout<<p.first<<" -> ";
            for(T neighbour : p.second) {
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(T src) {
        map<T,bool> visited;
        for(pair<T,list<T> > vertices : l) {
            visited[vertices.first] = false;
        }
        visited[src] = true;
        queue<T> q;
        q.push(src);
        while(!q.empty()) {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(T neighbour : l[node]) {
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
    void shortest_path_bfs(T src) {
        map<T,int> dist;
        for(pair<T,list<T> > p : l) {
            dist[p.first] = INT_MAX;
        }
        dist[src] = 0;
        queue<T> q;
        q.push(src);
        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(T neighbour : l[node]) {
                if(dist[neighbour]==INT_MAX) {
                    dist[neighbour] = dist[node] + 6;
                    q.push(neighbour);
                }
            }
        }
        for(pair<T,int> p : dist) {
            if(p.first==src) {
                continue;
            }
            if(p.second==INT_MAX) {
                cout<<-1<<" ";
            }
            else {
                cout<<p.second<<" ";
            }
        }
    }
};

int main() {
    int q;
    cin>>q;
    while(q--) {
        int v,e;
        cin>>v>>e;
        Graph<int> g(v);
        for(int i=0;i<e;i++) {
            int x,y;
            cin>>x>>y;
            g.addEdge(x,y);
        }
        int src;
        cin>>src;
        g.shortest_path_bfs(src);
        cout<<endl;
    }
    return 0;
}
