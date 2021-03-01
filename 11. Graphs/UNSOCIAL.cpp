#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

int mx;

bool isSafe(int i,int j,int n,int m) {
    return (i>=0 && j>=0 && i<n && j<m);
}

int dfs(vector<vector<int> > &mat) {
    int n = mat.size();
	int m = mat[0].size();
    vector<vector<int> > d(n,vector<int>(m,0));
    vector<vector<bool> > visisted(n,vector<bool>(m,false));
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++) {
	    for(int j=0;j<m;j++) {
    	    if(mat[i][j]==mx) {
    	        q.push(make_pair(i,j));
    	        visisted[i][j] = true;
    	    }
	    }
	}
	int ans = 0;
	while(!q.empty()) {
	    pair<int,int> p = q.front();
	    q.pop();
	    int x = p.first;
	    int y = p.second;
	    for(int i=0;i<8;i++) {
	        if(isSafe(x+dx[i],y+dy[i],n,m)) {
	            if(!visisted[x+dx[i]][y+dy[i]]) {
	                d[x+dx[i]][y+dy[i]] = d[x][y] + 1;
	                ans = max(ans,d[x+dx[i]][y+dy[i]]);
	                q.push({x+dx[i],y+dy[i]});
	                visisted[x+dx[i]][y+dy[i]] = true;
	            }
	        }
	    }
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > mat(n,vector<int>(m));
	    mx = 0;
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<m;j++) {
    	        cin>>mat[i][j];
    	        mx = max(mx,mat[i][j]);
	        }
	    }
	    cout<<dfs(mat)<<endl;
	}
	return 0;
}
