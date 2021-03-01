#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,cap;
	cin>>n>>cap;
	vector<int> wt(n),val(n);
	for(int i=0;i<n;i++) {
		cin>>wt[i];
	}
	for(int i=0;i<n;i++) {
		cin>>val[i];
	}
	vector<vector<int> > dp(n+1,vector<int>(cap+1,0));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=cap;j++) {
			if( j < wt[i-1] ) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				int ans = dp[i-1][j];
				for(int quantity = 1; j - quantity*wt[i-1]>=0; ++quantity) {
					ans = max(ans,dp[i-1][j-(quantity*wt[i-1])] + val[i-1]*quantity);
				}
				dp[i][j] = ans;
			}
		}
	}
	cout<<dp[n][cap];
	return 0;
}