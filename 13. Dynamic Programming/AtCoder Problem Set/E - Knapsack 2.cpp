#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long

struct item {
    int weight,value;
};

int32_t main() {
	int n,w;
	cin>>n>>w;
	vector<item> a(n+1);
	for(int i=1;i<=n;i++) {
	    cin>>a[i].weight>>a[i].value;
	}
	int max_val = n*1000;
	vector<vector<int> > dp(n+1,vector<int>(max_val+1));
	dp[1][0] = 0;
	for(int j=1;j<=max_val;j++) {
	    dp[1][j] = INT_MAX;
	}
	dp[1][a[1].value] = a[1].weight;
	for(int i=2;i<=n;i++) {
	    for(int j=0;j<=max_val;j++) {
	        dp[i][j] = dp[i-1][j];
	        if(a[i].value > j) {
	            continue;
	        }
	        else {
	            dp[i][j] = min(dp[i-1][j],a[i].weight + dp[i-1][j-a[i].value]);
	        }
	    }
	}
	int ans = 0;
	for(int j=0;j<=max_val;j++) {
	    if(dp[n][j] <= w) {
	        ans = j;
	    }
	}
	cout<<ans;
	return 0;
}
