#include<iostream>
#include<vector>
using namespace std;

int main() {
	string text,pattern;
	cin>>text;
	cin>>pattern;
	vector<vector<bool> > dp(text.length()+1,vector<bool>(pattern.length()+1,false));
	dp[0][0] = true;
	for(int i=1;i<=pattern.length();i++) {
		if(pattern[i-1]=='*') {
			dp[0][i] = dp[0][i-1];
		}
	}
	for(int i=1;i<=text.length();i++) {
		for(int j=1;j<=pattern.length();j++) {
			if(pattern[j-1]==text[i-1] || pattern[j-1]=='?') {
				dp[i][j] = dp[i-1][j-1];
			}
			else if(pattern[j-1]=='*') {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}
	if(dp[text.length()][pattern.length()]) {
		cout<<"MATCHED";
	}
	else {
		cout<<"NOT MATCHED";
	}
	return 0;
}