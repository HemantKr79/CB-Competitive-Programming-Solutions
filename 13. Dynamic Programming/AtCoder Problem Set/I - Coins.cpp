#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double solve(vector<double> &p,int n,int x,vector<vector<double> > &dp) {
    if(x==0) {
        return 1;
    }
    if(n==0) {
        return 0;
    }
    if(dp[n][x]>-0.9) {
        return dp[n][x];
    }
    return dp[n][x] = p[n]*solve(p,n-1,x-1,dp) + (1-p[n])*solve(p,n-1,x,dp);
}

int main() {
	int n;
	cin>>n;
	vector<double> p(n+1);
	for(int i=1;i<=n;i++) {
	    cin>>p[i];
	}
	vector<vector<double> > dp(n+1,vector<double>(n+1,-1));
	cout<<fixed<<setprecision(10)<<solve(p,n,(n+1)/2,dp);
	return 0;
}
