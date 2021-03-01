#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph {
    int v;
    map<T,list<T> > l;
    bool isCyclic_helper(T node,map<T,bool> &visited,T parent) {
        visited[node] = true;
        for(auto nbr : l[node]) {
            if(!visited[nbr]) {
                if(isCyclic_helper(nbr,visited,node)) {
                    return true;
                }
            }
            else if(nbr!=parent) {
                return true;
            }
        }
        return false;
    }
    public:
    Graph(int v) {
        this->v = v;
    }
    void addEdge(T x,T y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool isCyclic() {
        map<T,bool> visited;
        for(auto item : l) {
            visited[item.first] = false;
        }
        T starting_node = (*(visited.begin())).first;
        return isCyclic_helper(starting_node,visited,starting_node);
    }
};

int main() {
	Graph<int> g(3);
	g.addEdge(0,1);
	g.addEdge(0,2);
	cout<<g.isCyclic();
	return 0;
}
