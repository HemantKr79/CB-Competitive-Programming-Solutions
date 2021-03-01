#include<iostream>
#include<map>
#include<set>
#include<list>
#include<climits>
using namespace std;

template<typename T>
class Graph {
	int v;
	map<T,list<pair<T,int> > > l;
	public:
	Graph(int v) {
		this->v = v;
	}
	void addEdge(T x,T y,int w) {
		l[x].push_back(make_pair(y,w));
		l[y].push_back(make_pair(x,w));
	}
	void dijkstra(T src,T dest) {
		map<T,int> dist;
		for(auto item : l) {
			dist[item.first] = INT_MAX;
		}
		dist[src] = 0;
		set< pair<int,T> > s;
		s.insert(make_pair(0,src));
		while(!s.empty()) {
			pair<int,T> node = (*s.begin());
			s.erase(s.begin());
			int distance = node.first;
			T parent = node.second;
			for(pair<T,int> nbr : l[parent]) {
				if(distance + nbr.second < dist[nbr.first]) {
					pair<int,T> tmp = make_pair(dist[nbr.first],nbr.first);
					auto it = s.find(tmp);
					if(it!=s.end()) {
						s.erase(it);
					}
					dist[nbr.first] = distance + nbr.second;
					tmp.first = dist[nbr.first];
					s.insert(tmp);
				}
			}
		}
		cout<<dist[dest];
	}
};

int main() {
	int t;
	cin>>t;
	int cnt = 1;
	while(t--) {
		int n,x1,y1,x2,y2,w;
		cin>>n;
		Graph<pair<int,int> > g(4000000);
		cin>>x1>>y1;
		pair<int,int> src = make_pair(x1,y1);
		cin>>x2>>y2;
		pair<int,int> dest = make_pair(x2,y2);
		for(int i=0;i<n;i++) {
			cin>>x1>>y1>>x2>>y2>>w;
			g.addEdge(make_pair(x1,y1),make_pair(x2,y2),w);
		}
		x1 = src.first;
		y1 = src.second;
		x2 = dest.first;
		y2 = dest.second;
		if(x1<x2) {
			if(y1<y2) {
				for(int i=x1;i<=x2;i++) {
					for(int j=y1;j<=y2;j++) {
						g.addEdge(make_pair(i,j),make_pair(i+1,j),1);
						g.addEdge(make_pair(i,j),make_pair(i,j+1),1);
					}
				}
			}
			else {
				for(int i=x1;i<=x2;i++) {
					for(int j=y1;j>=y2;j--) {
						g.addEdge(make_pair(i,j),make_pair(i+1,j),1);
						g.addEdge(make_pair(i,j),make_pair(i,j-1),1);
					}
				}
			}
		}
		else {
			if(y1<y2) {
				for(int i=x1;i>=x2;i--) {
					for(int j=y1;j<=y2;j++) {
						g.addEdge(make_pair(i,j),make_pair(i-1,j),1);
						g.addEdge(make_pair(i,j),make_pair(i,j+1),1);
					}
				}
			}
			else {
				for(int i=x1;i>=x2;i--) {
					for(int j=y1;j>=y2;j--) {
						g.addEdge(make_pair(i,j),make_pair(i-1,j),1);
						g.addEdge(make_pair(i,j),make_pair(i,j-1),1);
					}
				}
			}
		}
		cout<<"#"<<cnt<<" : ";
		g.dijkstra(src,dest);
		++cnt;
		cout<<endl;
	}
	return 0;
}