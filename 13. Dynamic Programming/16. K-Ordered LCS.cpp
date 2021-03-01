#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > dp(n+1,vector<int>(m+1,0));
	vector<int> a(n+1);
	vector<int> b(m+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>b[i];
		if(k>0) {
			b[i] = a[i];
			--k;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i]==b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}