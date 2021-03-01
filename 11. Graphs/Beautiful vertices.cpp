#include<iostream>
#include<vector>
#include<set>
using namespace std;

int master;
int colorful_verices = 0;

void dfs(int cur,vector<int> *gr,vector<int> &par,vector<int> &child,vector<bool> &visited,vector<int> &Par) {
	visited[cur] = true;
	for(auto nbr : gr[cur]) {
		if(nbr!=master) {
			par[nbr]++;
			if(!visited[nbr]) {
				Par[nbr] = cur;
				child[cur]++;
				dfs(nbr,gr,par,child,visited,Par);
			}
		}
	}
}

int main() {
	int n,m,u,v;
	cin>>n>>m;
	vector<int> gr[n+1];
	vector<int> par(n+1,0);
	vector<int> child(n+1,0);
	vector<int> Par(n+1,0);
	vector<bool> visited(n+1,false);
	set<int> s;
	for(int i=0;i<m;i++) {
		cin>>u>>v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			master = i;
			s.insert(master);
			par[master] = 0;
			dfs(i,gr,par,child,visited,Par);
		}
	}
	for(int i=1;i<=n;i++) {
		if(s.find(i)==s.end()) {
			if(par[i]>child[i]) {
				colorful_verices++;
				cout<<i<<" ";
			}
		}
	}
	cout<<colorful_verices;
	return 0;
}