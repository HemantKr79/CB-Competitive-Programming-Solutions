#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define MOD 1000000007

int32_t main() {
	int n,m,p;
	cin>>n>>m>>p;
	vector<vector<int> > mat(n+1,vector<int>(m+1,0));
	for(int i=0;i<p;i++) {
	    int x,y;
	    cin>>x>>y;
	    mat[x][y] = 1;
	}
	vector<vector<int> > dp(n+1,vector<int>(m+1));
	if(mat[1][1]) {
	    cout<<0;
	    return 0;
	}
	dp[1][1] = 1;
	bool isBlocked = false;
	for(int i=2;i<=n;i++) {
	    if(mat[i][1]) {
	        isBlocked = true;
	    }
	    if(isBlocked) {
	        dp[i][1] = 0;
	    }
	    else {
	        dp[i][1] = 1;
	    }
	}
	isBlocked = false;
	for(int j=2;j<=m;j++) {
	    if(mat[1][j]) {
	        isBlocked = true;
	    }
	    if(isBlocked) {
	        dp[1][j] = 0;
	    }
	    else {
	        dp[1][j] = 1;
	    }
	}
	for(int i=2;i<=n;i++) {
	    for(int j=2;j<=m;j++) {
	        if(mat[i][j]) {
	            dp[i][j] = 0;
	        }
	        else {
	            dp[i][j] = dp[i-1][j] + dp[i][j-1];
	            dp[i][j] %= MOD;
	        }
	    }
	}
	cout<<dp[n][m];
	return 0;
}
