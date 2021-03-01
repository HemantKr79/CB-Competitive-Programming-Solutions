#include <iostream>
#include <vector>
using namespace std;

#define int long long

int32_t main() {
	int n,w;
	cin>>n>>w;
	//items.first contains weight and item.second contains value
	vector<pair<int,int> > items(n);
	for(int i=0;i<n;i++) {
	    cin>>items[i].first;
	    cin>>items[i].second;
	}
	vector<vector<int> > dp(n,vector<int>(w+1,0));
	if(items[0].first <= w) {
	    dp[0][items[0].first] = items[0].second;
	}
	for(int i=1;i<n;i++) {
	    for(int j=0;j<=w;j++) {
	        dp[i][j] = dp[i-1][j];
	        if(j-items[i].first >=0) {
	            dp[i][j] = max(items[i].second + dp[i-1][j-items[i].first],dp[i][j]);
	        }
	    }
	}
	int ans = 0;
	for(int i=0;i<=w;i++) {
	    ans = max(ans,dp[n-1][i]);
	}
	cout<<ans;
	return 0;
}
