#include <iostream>
#include <string>
#include <vector>
using namespace std;

int len(string &s,string &t,int i,int j,vector<vector<int> > &dp) {
    if(i >= s.length() || j >=t.length()) {
        return 0;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    if(s[i]==t[j]) {
        return dp[i][j] = 1 + len(s,t,i+1,j+1,dp);
    }
    else {
        int option1 = len(s,t,i+1,j,dp);
        int option2 = len(s,t,i,j+1,dp);
        return dp[i][j] = max(option1,option2);
    }
}

string get_lcs(string &s,string &t,int l,vector<vector<int> > &dp) {
    string str;
    str.reserve(l);
    int i=0,j=0;
    while(l > 0) {
        if(s[i]==t[j]) {
            str.push_back(s[i]);
            ++i;
            ++j;
            --l;
        }
        else {
            if(dp[i+1][j] > dp[i][j+1]) {
                ++i;
            }
            else {
                ++j;
            }
        }
    }
    return str;
}

int main() {
	string s,t;
	cin>>s>>t;
	int n = s.length();
	int m = t.length();
	vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
	int l = len(s,t,0,0,dp);
	cout<<get_lcs(s,t,l,dp);
	return 0;
}
