#include<iostream>
using namespace std;

int solve(int n) {
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = new int[2];
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i=2;i<=n;i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][1] = dp[i-1][0] + dp[i-1][1];
	}
	int ans = dp[n][0] + dp[n][1];
	for(int i=0;i<=n;i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return ans;
}

int main() {
	int t;
	cin>>t;
	int cnt = 1;
	while(t--) {
		int n;
		cin>>n;
		cout<<"#"<<cnt<<" : ";
		cout<<solve(n)<<endl;
		cnt++;
	}
	return 0;
}