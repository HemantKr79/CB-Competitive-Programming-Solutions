#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class Graph {
	int v;
	vector<T> vertices;
	map<T,list<T> > l;
	void topological_sort_helper(T node,map<T,bool> &visisted,list<T> &ts) {
		visisted[node] = true;
		for(auto neighbour : l[node]) {
			if(!visisted[neighbour]) {
				topological_sort_helper(neighbour,visisted,ts);
			}
		}
		ts.push_front(node);
	}
	void topological_sort_bfs_helper(T node,map<T,bool> &visisted,map<T,int> &indegree) {
		visisted[node] = true;
		for(auto neighbour : l[node]) {
			indegree[neighbour]++;
			if(!visisted[neighbour]) {
				topological_sort_bfs_helper(neighbour,visisted,indegree);
			}
		}
	}
	public:
	Graph(int v) {
		this->v = v;
		vertices.reserve(v);
	}
	void addEdge(T src,T dest,bool bidirectional=false) {
		l[src].push_back(dest);
		if(bidirectional) {
			l[dest].push_back(src);
		}
	}
	void addVertex(T &node) {
		vertices.push_back(node);
	}
	void topological_sort() {
		map<T,bool> visisted;
		for(int i=0;i<v;i++) {
			visisted[vertices[i]] = false;
		}
		list<T> ts;
		for(int i=0;i<v;i++) {
			if(!visisted[vertices[i]]) {
				topological_sort_helper(vertices[i],visisted,ts);
			}
		}
		for(auto item : ts) {
			cout<<item<<" ";
		}
	}
	void topological_sort_bfs() {
		map<T,int> indegree;
		map<T,bool> visisted;
		for(int i=0;i<v;i++) {
			indegree[vertices[i]] = 0;
			visisted[vertices[i]] = false;
		}
		for(int i=0;i<v;i++) {
			if(!visisted[vertices[i]]) {
				topological_sort_bfs_helper(vertices[i],visisted,indegree);
			}
		}
		queue<T> q;
		for(int i=0;i<v;i++) {
			visisted[vertices[i]] = false;
		}
		for(int i=0;i<v;i++) {
			if(indegree[vertices[i]]==0) {
				q.push(vertices[i]);
				visisted[vertices[i]] = true;
				break;
			}
		}
		while(!q.empty()) {
			cout<<" "<<q.front();
			T node = q.front();
			q.pop();
			for(auto neighbour : l[node]) {
				if(!visisted[neighbour] && indegree[neighbour]>0) {
					indegree[neighbour] -= 1;
				}
			}
			for(int i=0;i<v;i++) {
				if(indegree[vertices[i]]==0 && !visisted[vertices[i]]) {
					q.push(vertices[i]);
					visisted[vertices[i]] = true;
					break;
				}
			}
		}
	}
};

int main() {
	int c = 1;
	int n;
	while(cin>>n) {
		Graph<string> g(n);
		for(int i=0;i<n;i++) {
			string node;
			cin>>node;
			g.addVertex(node);
		}
		int e;
		cin>>e;
		for(int i=0;i<e;i++) {
			string src,dest;
			cin>>src>>dest;
			g.addEdge(src,dest);
		}
		cout<<"Case #"<<c<<": Vivek should drink beverages in this order:";
		g.topological_sort_bfs();
		cout<<".\n";
		++c;
	}
	return 0;
}