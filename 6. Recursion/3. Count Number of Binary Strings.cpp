#include<iostream>
using namespace std;

#define ll long long

ll count_binary_string(ll n) {
	ll **dp = new ll*[n+1];
	for(ll i=0;i<=n;i++) {
		dp[i] = new ll[2];
	}
	dp[0][0] = dp[0][1] = 0;
	dp[1][0] = dp[1][1] = 1;
	for(int i=2;i<=n;i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	ll ans = dp[n][0] + dp[n][1];
	for(int i=0;i<=n;i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		cout<<count_binary_string(n)<<endl;
	}
	return 0;
}