#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,s;
	cin>>n>>s;
	vector<int> space(n);
	for(int i=0;i<n;i++) {
		cin>>space[i];
	}
	vector<int> value(n);
	for(int i=0;i<n;i++) {
		cin>>value[i];
	}
	vector<vector<int> > dp(n+1,vector<int>(s+1,0));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=s;j++) {
			if(j < space[i-1]) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j],value[i-1] + dp[i-1][j-space[i-1]]);
			}
		}
	}
	cout<<dp[n][s];
	return 0;
}