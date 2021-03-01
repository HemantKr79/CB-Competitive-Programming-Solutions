#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define MOD 1000000007

int32_t main() {
	int h,w;
	cin>>h>>w;
	vector<vector<char> > mat(h,vector<char>(w));
	for(int i=0;i<h;i++) {
	    for(int j=0;j<w;j++) {
	        cin>>mat[i][j];
	    }
	}
	vector<vector<int> > dp(h,vector<int>(w));
	dp[0][0] = 1;
	bool isbloked = false;
	for(int i=1;i<h;i++) {
	    if(mat[i][0]=='#') {
	        isbloked = true;
	    }
	    if(isbloked) {
	        dp[i][0] = 0;
	    }
	    else {
	        dp[i][0] = dp[i-1][0];
	    }
	}
	isbloked = false;
	for(int j=1;j<w;j++) {
	    if(mat[0][j]=='#') {
	        isbloked = true;
	    }
	    if(isbloked) {
	        dp[0][j] = 0;
	    }
	    else {
	        dp[0][j] = dp[0][j-1];
	    }
	}
	for(int i=1;i<h;i++) {
	    for(int j=1;j<w;j++) {
	        if(mat[i][j]=='#') {
	            dp[i][j] = 0;
	        }
	        else {
	            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
	        }
	    }
	}
	cout<<dp[h-1][w-1];
	return 0;
}
