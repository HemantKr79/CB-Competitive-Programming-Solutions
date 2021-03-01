#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
using namespace std;

class Graph {
	int v;
	map<string,list<string> > l;
	public:
	Graph(int v) {
		this->v = v;
	}
	void addVertex(string str) {
		list<string> tmp;
		l[str] = tmp;
	}
	void addEdge(string scr,string dest) {
		l[scr].push_back(dest);
	}
	void topological_sort_helper(string scr,list<string> &order,map<string,bool> &visited) {
		visited[scr] = true;
		for(auto nbr : l[scr]) {
			if(!visited[nbr]) {
				topological_sort_helper(nbr,order,visited);
			}
		}
		order.push_front(scr);
	}
	void topological_sort() {
		string src = (*l.begin()).first;
		list<string> order;
		map<string,bool> visited;
		for(auto item : l) {
			visited[item.first] = false;
		}
		for(auto item : l) {
			if(visited[item.first]==false) {
				topological_sort_helper(item.first,order,visited);
			}
		}
		for(auto item : order) {
			cout<<item<<" ";
		}
	}
	void print() {
		for(auto item : l) {
			cout<<item.first<<" : ";
			for(auto tmp : item.second) {
				cout<<tmp<<" ";
			}
			cout<<endl;
		}
	}
};

int main() {
	int v = -1;
	int c = 1;
	cin>>v;
	while(v!=-1) {
		string tmp,dest;
		Graph g(v);
		for(int i=0;i<v;i++) {
			cin>>tmp;
			g.addVertex(tmp);
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++) {
			cin>>tmp>>dest;
			g.addEdge(tmp,dest);
		}
		cout<<"Case #"<<c++<<": ";
		g.topological_sort();
		cout<<endl;
		g.print();
		v = -1;
		cin>>v;
	}
	return 0;
}