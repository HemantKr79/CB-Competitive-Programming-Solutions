#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

void printmat(int **mat,int r,int c) {
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			cout<<mat[i][j];
		}
		cout<<endl;
	}
}

void floodfill(int **mat,int i,int j,int r,int c,int to_replace,int replace_by,int &cnt) {
	if(i<0 || j<0 || i>=r || j>=c) {
		return;
	}
	if(mat[i][j]!=to_replace) {
		return;
	}
	++cnt;
	mat[i][j] = replace_by;
	for(int x=0;x<4;x++) {
		floodfill(mat,i+dx[x],j+dy[x],r,c,to_replace,replace_by,cnt);
	}
}


int main() {
	int r,c;
	cin>>r>>c;
	int **mat = new int*[r];
	for(int i=0;i<r;i++) {
		mat[i] = new int[c];
		for(int j=0;j<c;j++) {
			cin>>mat[i][j];
		}
	}
	unordered_map<int,int> m;
	int p = 2;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(mat[i][j]==1) {
				int cnt = 0;
				floodfill(mat,i,j,r,c,1,p,cnt);
				m.insert(make_pair(p,cnt));
				++p;
			}
		}
	}
	m.insert(make_pair(0,0));
	unordered_set<int> s;
	int ans = 0;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(mat[i][j]==0) {
				int neighbours = 0;
				for(int x=0;x<4;x++) {
					int u = i+dx[x];
					int v = j+dy[x];
					if(u>=0 && v>=0 && u<r && v<c) {
						s.insert(mat[u][v]);
					}
				}
				for(auto item : s) {
					neighbours += m[item];
				}
				s.clear();
				ans = max(ans,1+neighbours);
			}
		}
	}
	cout<<ans;
	return 0;
}