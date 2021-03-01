#include<iostream>
#include<cstring>
using namespace std;

int n,k;
int dp[102][2][102][102];

void set_dp() {
	memset(dp,-1,sizeof(dp));
}

int profit(int *a,int i,int cont,int prev,int transaction) {
	if(i==n) {
		return 0;
	}
	if(transaction==k) {
		return 0;
	}
	if(dp[i][cont][prev][transaction]!=-1) {
		return dp[i][cont][prev][transaction];
	}
	int ans = 0;
	if(cont) {
		int option1 = a[i] - a[prev] + profit(a,i+1,0,0,transaction+1);
		int option2 = profit(a,i+1,1,prev,transaction);
		ans = max(ans,max(option1,option2));
	}
	else {
		int option1 = profit(a,i+1,1,i,transaction);
		int option2 = profit(a,i+1,0,0,transaction);
		ans = max(ans,max(option1,option2));
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>k>>n;
		set_dp();
		int *a = new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		cout<<profit(a,0,0,0,0)<<endl;
	}
	return 0;
}