#include<iostream>
#include<vector>
using namespace std;

int n,m;

int main () {
	cin>>n>>m;
	vector<vector<int> > field(n+1,vector<int>(n+1,0));
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		field[x][y] = 1;
	}
	vector<vector<int> > dp(n+1,vector<int>(n+1,0));
	dp[1][1] = field[1][1];
	for(int i=2;i<=n;i++) {
		dp[i][1] = dp[i-1][1] + field[i][1];
	}
	for(int j=2;j<=n;j++) {
		dp[1][j] = dp[1][j-1] + field[1][j];
	}
	for(int i=2;i<=n;i++) {
		int cum_sum = field[i][1];
		for(int j=2;j<=n;j++) {
			cum_sum += field[i][j];
			dp[i][j] = cum_sum + dp[i-1][j];
		}
	}
	int ans = 0;
	for(int i=1;i<n;i++) {
		for(int j=1;j<n;j++) {
			int option1 = dp[i][j];
			int option2 = dp[i][n] - dp[i][j];
			int option3 = dp[n][j] - dp[i][j];
			int option4 = m - (option1+option2+option3);
			ans = max(ans,min(min(option1,option2),min(option3,option4)));
		}
	}
	cout<<ans;
	return 0;
}