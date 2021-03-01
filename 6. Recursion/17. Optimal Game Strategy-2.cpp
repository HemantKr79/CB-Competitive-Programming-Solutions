#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	vector<vector<int> > dp(n,vector<int>(n,0));
	int s=0;
	int e=1;
	while(e<n) {
		dp[s][e] = max(a[s],a[e]);
		++s;
		++e;
	}
	for(int j=3;j<n;j+=2) {
		s = 0;
		e = j;
		while(e<n) {
			//if we choose s
			int ans1 = a[s] + min(dp[s+2][e],dp[s+1][e-1]);
			//if we choose e
			int ans2 = a[e] + min(dp[s+1][e-1],dp[s][e-2]);
			dp[s][e] = max(ans1,ans2);
			++s;
			++e;
		}
	}
	cout<<dp[0][n-1];
	return 0;
}