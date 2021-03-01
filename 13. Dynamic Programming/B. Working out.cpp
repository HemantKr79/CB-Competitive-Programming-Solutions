#include <iostream>
#include <vector>
using namespace std;

#define int long long

int32_t main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int> > mat(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++) {
	    for(int j=1;j<=m;j++) {
	        cin>>mat[i][j];
	    }
	}
	vector<vector<int> > dp1(n+1,vector<int>(m+1,0));
	vector<vector<int> > dp2(n+1,vector<int>(m+1,0));
	vector<vector<int> > dp3(n+1,vector<int>(m+1,0));
	vector<vector<int> > dp4(n+1,vector<int>(m+1,0));
	//filling up d1
	for(int i=1;i<=n;i++) {
	    for(int j=1;j<=m;j++) {
	        dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]) + mat[i][j];
	    }
	}
	//filling up dp2
	int c_sum = 0;
	for(int i=1;i<=n;i++) {
	    c_sum += mat[i][m];
	    dp2[i][m] = c_sum;
	}
	c_sum = 0;
	for(int j=m;j>=1;j--) {
	    c_sum += mat[1][j];
	    dp2[1][j] = c_sum;
	}
	for(int i=2;i<=n;i++) {
	    for(int j=m-1;j>0;j--) {
	        dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1]) + mat[i][j];
	    }
	}
	//fill up dp3
	c_sum = 0;
	for(int j=1;j<=m;j++) {
	    c_sum += mat[n][j];
	    dp3[n][j] = c_sum;
	}
	c_sum = 0;
	for(int i=n;i>0;i--) {
	    c_sum += mat[i][1];
	    dp3[i][1] = c_sum;
	}
	for(int i=n-1;i>0;i--) {
	    for(int j=2;j<=m;j++) {
	        dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1]) + mat[i][j];
	    }
	}
	//filling up dp4
	c_sum = 0;
	for(int i=n;i>0;i--) {
	    c_sum += mat[i][m];
	    dp4[i][m] = c_sum;
	}
	c_sum = 0;
	for(int j=m;j>0;j--) {
	    c_sum += mat[n][j];
	    dp4[n][j] = c_sum;
	}
	for(int i=n-1;i>0;i--) {
	    for(int j=m-1;j>0;j--) {
	        dp4[i][j] = max(dp4[i+1][j],dp4[i][j+1]) + mat[i][j];
	    }
	}
	int ans = 0;
	for(int i=2;i<n;i++) {
	    for(int j=2;j<m;j++) {
	        int option1 = dp1[i-1][j] + dp2[i][j+1] + dp3[i][j-1] + dp4[i+1][j];
	        int option2 = dp1[i][j-1] + dp2[i-1][j] + dp3[i+1][j] + dp4[i][j+1];
	        ans = max(ans,max(option1,option2));
	    }
	}
	cout<<ans;
	return 0;
}
