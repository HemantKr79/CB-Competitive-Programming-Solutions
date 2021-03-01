#include<iostream>
#include<vector>
using namespace std;

#define int long long
#define mod 1000000007

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int m;
		cin>>m;
		vector<int> coins(m);
		for(int i=0;i<m;i++) {
			cin>>coins[i];
		}
		int n;
		cin>>n;
		vector<int> dp(n+1,0);
		dp[0] = 1;
		for(int i=0;i<m;i++) {
			for(int j=coins[i];j<=n;j++) {
				dp[j] = (dp[j] + dp[j-coins[i]])%mod;
			}
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}