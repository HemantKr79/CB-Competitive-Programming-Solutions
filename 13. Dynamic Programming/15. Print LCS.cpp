#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string a,b;
	cin>>a;
	cin>>b;
	vector<vector<int> > dp(a.length()+1,vector<int>(b.length()+1,0));
	for(int i=1;i<=a.length();i++) {
		for(int j=1;j<=b.length();j++) {
			if(a[i-1]==b[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string answer;
	answer.reserve(dp[a.length()][b.length()]);
	int i = a.length();
	int j = b.length();
	while(i>0 && j>0) {
		if(dp[i-1][j]==dp[i][j]) {
			--i;
			continue;
		}
		else if(dp[i][j-1]==dp[i][j]) {
			--j;
			continue;
		}
		if(dp[i][j] == dp[i-1][j-1] + 1) {
			answer.push_back(a[i-1]);
			--i;
			--j;
		}
		else {
			if(dp[i-1][j] >= dp[i][j-1]) {
				--i;
			}
			else {
				--j;
			}
		}
	}
	reverse(answer.begin(),answer.end());
	cout<<answer;
	return 0;
}