#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int v;
    list<int> *l;
    bool contains_cycle_helper(int node,bool *visited,bool *stack) {
        visited[node] = true;
        stack[node] = true;
        for(auto nbr : l[node]) {
            if(stack[nbr]==true) {
                return true;
            }
            else if(visited[nbr]==false) {
                if(contains_cycle_helper(nbr,visited,stack)) {
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;
    }
    public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x,int y) {
        l[x].push_back(y);
    }
    bool contains_cycle() {
        bool *visited = new bool[v];
        bool *stack = new bool[v];
        for(int i=0;i<v;i++) {
            visited[i] = stack[i] = false;
        }
        for(int i=0;i<v;i++) {
            if(visited[i]==false) {
                if(contains_cycle_helper(i,visited,stack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,2);
    cout<<g.contains_cycle();
    return 0;
}
