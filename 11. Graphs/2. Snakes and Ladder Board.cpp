#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

class Graph {
	int v;
	map<int,list<int> > l;
	public:
	Graph(int v) {
		this->v = v;
		list<int> tmp;
		for(int i=1;i<=v;i++) {
			l[i] = tmp;
		}
	}
	void addEdge(int x,int y) {
		l[x].push_back(y);
	}
	int shortest_path(int src,int dest) {
		map<int,int> dist;
		for(auto item : l) {
			dist[item.first] = INT_MAX;
		}
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		while(!q.empty()) {
			int node = q.front();
			q.pop();
			for(auto neighbour : l[node]) {
				if(dist[neighbour]==INT_MAX) {
					dist[neighbour] = dist[node]+1;
					q.push(neighbour);
				}
			}
		}
		if(dist[dest]==INT_MAX) {
			return -1;
		}
		return dist[dest];
	}
};

int main() {
	int t;
	cin>>t;
	while(t--) {
		Graph g(100);
		int n,m,jump;
		cin>>n;
		int *board = new int[101];
		for(int i=0;i<101;i++) {
			board[i] = 0;
		}
		int start,end;
		for(int i=0;i<n;i++) {
			cin>>start>>end;
			board[start] = (end-start);
		}
		cin>>m;
		for(int i=0;i<m;i++) {
			cin>>start>>end;
			board[start] = (end-start);
		}
		for(int i=1;i<=100;i++) {
			for(int j=1;j<=6;j++) {
				jump = i+j;
				jump += board[jump];
				if(jump<=100) {					
					g.addEdge(i,jump);
				}
			}
		}
		cout<<g.shortest_path(1,100)<<endl;
	}
	return 0;
}