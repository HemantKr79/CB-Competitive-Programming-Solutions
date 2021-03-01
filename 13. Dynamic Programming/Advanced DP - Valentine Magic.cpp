#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
int inf = 1e18;
int n,m;

int solve(int i,int j,vector<int> &boys,vector<int> &girls,vector<vector<int> > &dp) {
    if(i==n) {
        return 0;
    }
    if(j==m) {
        return inf;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int option1 = abs(boys[i]-girls[j]) + solve(i+1,j+1,boys,girls,dp);
    int option2 = solve(i,j+1,boys,girls,dp);
    return dp[i][j] = min(option1,option2);
}

int32_t main() {
    cin>>n>>m;
    vector<int> boys(n);
    for(int i=0;i<n;i++) {
        cin>>boys[i];
    }
    vector<int> girls(m);
    for(int j=0;j<m;j++) {
        cin>>girls[j];
    }
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    vector<vector<int> > dp(n,vector<int>(m,-1));
    int ans = solve(0,0,boys,girls,dp);
    cout<<ans;
	return 0;
}