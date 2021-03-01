#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<set>
using namespace std;

template<typename T>
class Graph {
	map<T,list<pair<T,int> > > l;
	int v;
	public:
	Graph(int v) {
		list<pair<T,int> > tmp;
		for(int i=1;i<=v;i++) {
			l[i] = tmp;
		}
		this->v = v;
	}
	void addEdge(T x,T y,int w) {
		l[x].push_back(make_pair(y,w));
		l[y].push_back(make_pair(x,w));
	}
	map<T,int> dijkstra(T src) {
		map<T,int> dist;
		for(auto item : l) {
			dist[item.first] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int,T> > s;
		s.insert(make_pair(0,src));
		while(!s.empty()) {
			pair<int,T> p = (*s.begin());
			s.erase(s.begin());
			T node = p.second;
			int distance = p.first;
			for(pair<T,int> nbr : l[node]) {
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
		return dist;
	}
};

int main() {
	int t;
	cin>>t;
	while(t--) {
		int v,e,x,y,w,s;
		cin>>v>>e;
		Graph<int> g(v);
		for(int i=0;i<e;i++) {
			cin>>x>>y>>w;
			g.addEdge(x,y,w);
		}
		cin>>s;
		map<int,int> dist = g.dijkstra(s);
		int curr = 1;
		for(auto item : dist) {
			if(item.first == s) {
				continue;
			}
			if(item.second==INT_MAX) {
				cout<<-1<<" ";
			}
			else {
				cout<<item.second<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}