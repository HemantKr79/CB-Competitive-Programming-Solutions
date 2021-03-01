#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> dp(n+1,1e6);
	dp[0] = -1e6;
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	for(int i=0;i<n;i++) {
		int pos = upper_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
		if(dp[pos-1] < v[i] && dp[pos] > v[i]) {
			dp[pos] = v[i];
		}
	}
	int len = 0;
	for(int i=0;i<=n;i++) {
		if(dp[i]!=1e6) {
			len = i;
		}
	}
	cout<<len;
	return 0;
}