#include <iostream>
#include <list>
#include <map>
#include <forward_list>
#include <string>
using namespace std;

template<typename T>
class Graph {
    int v;
    map<T,list<T> > l;
    void topological_sort_helper(T src,map<T,bool> &visited,forward_list<T> &ordering) {
        visited[src] = true;
        for(auto nbr : l[src]) {
            if(!visited[nbr]) {
                topological_sort_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    public:
    Graph(int v) {
        this->v = v;
    }
    void addEdge(T x,T y) {
        l[x].push_back(y);
    }
    void topological_sort() {
        map<T,bool > visited;
        for(auto item : l) {
            visited[item.first] = false;
        }
        forward_list<T> ordering;
        for(auto item : visited) {
            if(!item.second) {
                topological_sort_helper(item.first,visited,ordering);
            }
        }
        for(auto item : ordering) {
            cout<<item<<endl;
        }
    }
};

int main() {
    int t;
    cin>>t;
    int cnt = 1;
    while(t--) {
        int n;
        cin>>n;
        Graph<string> g(n);
        string src,dest;
        for(int i=0;i<n-1;i++) {
            cin>>src;
            cin>>dest;
            g.addEdge(src,dest);
        }
        cout<<"Scenario #"<<cnt<<":"<<endl;
        cnt++;
        g.topological_sort();
        cout<<endl;
    }
    return 0;
}
