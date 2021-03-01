#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

int n,m;

int flood_fill(vector<vector<int> > &pond,int i,int j,int to_replace,int replace_by) {
	int cnt = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(i,j));
	pond[i][j] = replace_by;
	while(!q.empty()) {
		pair<int,int> f = q.front();
		int x = f.first;
		int y = f.second;
		++cnt;
		q.pop();
		if(x-1>=0 && pond[x-1][y]==to_replace) {
			pond[x-1][y] = replace_by;
			q.push(make_pair(x-1,y));
		}
		if(x+1<n && pond[x+1][y]==to_replace) {
			pond[x+1][y] = replace_by;
			q.push(make_pair(x+1,y));
		}
		if(y-1>=0 && pond[x][y-1]==to_replace) {
			pond[x][y-1] = replace_by;
			q.push(make_pair(x,y-1));
		}
		if(y+1<m && pond[x][y+1]==to_replace) {
			pond[x][y+1] = replace_by;
			q.push(make_pair(x,y+1));
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vector<vector<int> > pond(n,vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>pond[i][j];
		}
	}
	int col = 2;
	unordered_map<int,int> mp;
	mp.reserve(100000);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(pond[i][j]==1) {
				mp[col] = flood_fill(pond,i,j,1,col);
				++col;
			}
		}
	}
	set<int> s;
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(pond[i][j]==0) {
				int sz = 0;
				if(i-1>=0) {
					s.insert(pond[i-1][j]);
				}
				if(i+1<n) {
					s.insert(pond[i+1][j]);
				}
				if(j-1>=0) {
					s.insert(pond[i][j-1]);
				}
				if(j+1<m) {
					s.insert(pond[i][j+1]);
				}
				for(auto item : s) {
					sz += mp[item];
				}
				ans = max(ans,sz+1);
				s.clear();
			}
		}
	}
	cout<<ans;
	return 0;
}