#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> *gr,vector<bool> &visited,int cur,int &incomming) {
	visited[cur] = true;
	for(auto nbr : gr[cur]) {
		incomming++;
		if(!visited[nbr]) {
			dfs(gr,visited,nbr,incomming);
		}
	}
}

int main() {
	int v,e;
	cin>>v>>e;
	vector<int> gr[v+1];
	int x,y;
	for(int i=0;i<e;i++) {
		cin>>x>>y;
		gr[x].push_back(y);
	}
	vector<bool> visited(v+1,false);
	int ans = v+1;
	for(int i=1;i<=v;i++) {
		if(!visited[i]) {
			int incomming = 0;
			dfs(gr,visited,i,incomming);
			if(incomming>0) {
				ans = min(ans,incomming);
			}
		}
	}
	if(ans==v+1) {
		cout<<1;
	}
	else {
		cout<<ans;
	}
	cout<<endl;
	return 0;
}