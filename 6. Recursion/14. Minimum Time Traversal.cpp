#include<iostream>
#include<list>
#include<map>
#include<climits>
#include<set>
#include<vector>
using namespace std;

template<typename T>
class Graph {
	map<T,list<pair<T,int> > > l;
	public:
	void addEdge(T src,T dest,int cost) {
		l[src].push_back(make_pair(dest,cost));
		l[dest].push_back(make_pair(src,cost));
	}
	int dijkstra(T src,T dest) {
		map<T,int> dist;
		for(auto item : l) {
			dist[item.first] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int,T> > s;
		s.insert(make_pair(0,src));
		while(!s.empty()) {
			pair<int,T> tmp = *s.begin();
			int curr_dist = tmp.first;
			T node = tmp.second;
			s.erase(s.begin());
			for(auto nbr : l[node]) {
				T n = nbr.first;
				int weight = nbr.second;
				if(dist[n] > dist[node] + weight) {
					auto it = s.find(make_pair(dist[n],n));
					if(it!=s.end()) {
						s.erase(it);
					}
					dist[n] = dist[node] + weight;
					s.insert(make_pair(dist[n],n));
				}
			}
		}
		return dist[dest];
	}
	bool containsEdge(T src,T dest) {
		for(auto item : l[src]) {
			if(item.first==dest) {
				return true;
			}
		}
		return false;
	}
	void show_graph() {
		for(auto item : l) {
			cout<<item.first.first<<","<<item.first.second<<" -> ";
			for(auto x : item.second) {
				cout<<" ("<<x.first.first<<","<<x.first.second<<","<<x.second<<") ";
			}
			cout<<endl;
		}
	}
};

int main() {
	int t;
	cin>>t;
	int c = 1;
	while(t--) {		
		int n,a,b,x,y,cost;
		Graph<pair<int,int> > g;
		vector<pair<int,int> > vertices;
		cin>>n;
		int start_x,start_y,end_x,end_y;
		cin>>start_x>>start_y>>end_x>>end_y;
		vertices.push_back(make_pair(start_x,start_y));
		vertices.push_back(make_pair(end_x,end_y));
		for(int i=0;i<n;i++) {
			cin>>a>>b>>x>>y>>cost;
			g.addEdge(make_pair(a,b),make_pair(x,y),cost);
			vertices.push_back(make_pair(a,b));
			vertices.push_back(make_pair(x,y));
		}
		for(int i=0;i<vertices.size();i++) {
			for(int j=i+1;j<vertices.size();j++) {
				if(!g.containsEdge(vertices[i],vertices[j])) {
					cost = abs(vertices[j].first - vertices[i].first) + abs(vertices[j].second - vertices[i].second);
					g.addEdge(vertices[i],vertices[j],cost);
				}
			}
		}
		cout<<"#"<<c<<" : ";
		cout<<g.dijkstra(make_pair(start_x,start_y),make_pair(end_x,end_y));
		cout<<endl;
		++c;
	}
	return 0;
}