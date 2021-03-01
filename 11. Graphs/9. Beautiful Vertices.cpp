#include<iostream>
#include<vector>
using namespace std;

#define N 100001

vector<int> gr[N];
vector<int> children(N,0);
vector<int> parent(N);
vector<int> visited(N,false);

void dfs(int cur,int par) {
	parent[cur] = par;
	visited[cur] = true;
	for(auto x : gr[cur]) {
		if(x!=par) {
			dfs(x,cur);
			children[cur] += 1;
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(!visited[i]) {
			dfs(i,0);
			--ans;
		}
	}
	for(int i=1;i<=n;i++) {
		if(children[i] > children[parent[i]]) {
			++ans;
		}
	}
	cout<<ans;
	return 0;
}