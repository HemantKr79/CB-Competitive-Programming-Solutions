#include<iostream>
#include<vector>
using namespace std;

int solve(int *a,vector<vector<int> > &dp,int i,int j) {
	if(i>j) {
		return 0;
	}
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	//if we choose ith number
	int smallAns1 = solve(a,dp,i+2,j);
	int smallAns2 = solve(a,dp,i+1,j-1);
	int ans = a[i] + min(smallAns1,smallAns2);
	//if we choose jth number
	int smallAns3 = solve(a,dp,i,j-2);
	int smallAns4 = solve(a,dp,i+1,j-1);
	ans = max(ans,a[j] + min(smallAns3,smallAns4));
	dp[i][j] = ans;
	return ans;
}

int main() {
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int i=0;
	int j=n-1;
	vector<vector<int> > dp(n,vector<int>(n,-1));
	cout<<solve(a,dp,i,j);
	return 0;
}