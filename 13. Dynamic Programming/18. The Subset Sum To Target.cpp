#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s;
	cin>>n>>s;
	vector<int> st(n);
	for(int i=0;i<n;i++) {
		cin>>st[i];
	}
	vector<bool> dp(s+1,false);
	dp[0] = true;
	for(int i=1;i<=n;i++) {
		for(int j=st[i];j<=s;j++) {
			dp[j] = dp[j] || dp[j-st[i]];
		}
	}
	if(dp[s]) {
		cout<<"Yes";
	}
	else {
		cout<<"No";
	}
	return 0;
}