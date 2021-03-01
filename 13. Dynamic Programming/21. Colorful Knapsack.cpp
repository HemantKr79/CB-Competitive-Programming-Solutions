#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,m,x;
	cin>>n>>m>>x;
	vector<int> wt(n),c(n);
	for(int i=0;i<n;i++) {
		cin>>wt[i];
	}
	for(int i=0;i<n;i++) {
		cin>>c[i];
	}
	vector<int> color[m+1];
	for(int i=0;i<n;i++) {
		color[c[i]].push_back(wt[i]);
	}
	vector<vector<int> > dp(m+1,vector<int>(x+1,0));
	for(int i=1;i<=m;i++) {
		dp[i][0] = -1;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=x;j++) {
			int ans = -1;
			for(auto item : color[i]) {
				if(item <= j && dp[i-1][j-item]!=-1) {
					ans = max(ans,item+dp[i-1][j-item]);
				}
			}
			dp[i][j] = ans;
		}
	}
	if(dp[m][x]==-1) {
		cout<<-1;
	}
	else {
		cout<<x-dp[m][x];
	}
	return 0;
}