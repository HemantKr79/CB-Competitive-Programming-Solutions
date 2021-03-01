#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph {
    int v;
    map<T,list<T> > l;
    void dfs_helper(T src,map<T,bool> &visited) {
        cout<<src<<" ";
        visited[src] = true;
        for(T neighbour : l[src]) {
            if(!visited[neighbour]) {
                dfs_helper(neighbour,visited);
            }
        }
    }
    public:
    Graph(int v) {
        this->v = v;
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
    void dfs(T src) {
        map<T,bool> visited;
        for(pair<T,list<T> > p : l) {
            visited[p.first] = false;
        }
        dfs_helper(src,visited);
    }
};

int main() {
    int v,e;
    cin>>v>>e;
    Graph<int> g(v);
    for(int i=0;i<e;i++) {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.print_adjacency_list();
    cout<<"BFS Traversal : ";
    g.bfs(0);
    cout<<endl<<"DFS Traversal: ";
    g.dfs(0);
    return 0; 
}
