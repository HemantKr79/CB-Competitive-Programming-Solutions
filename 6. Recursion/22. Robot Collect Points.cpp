#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define inf -1e9

void set_prob(vector<vector<int> > &tmp,vector<vector<int> > &mat,vector<vector<int> > &dp) {
	for(int i=0;i<tmp.size();i++) {
		for(int j=0;j<5;j++) {
			tmp[i][j] = mat[i][j];
			dp[i][j] = inf;
		}
	}
}

int solve(vector<vector<int> > &dp,vector<vector<int> > &tmp,int i,int j) {
	if(i<0 || j<0 || j>4) {
		return 0;
	}
	if(dp[i][j]!=inf) {
		return dp[i][j];
	}
	int option1 = solve(dp,tmp,i-1,j-1);
	int option2 = solve(dp,tmp,i-1,j);
	int option3 = solve(dp,tmp,i-1,j+1);
	return dp[i][j] = max(option1,max(option2,option3)) + tmp[i][j];
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<vector<int> > dp(n,vector<int>(5,-1));
		vector<vector<int> > mat(n,vector<int>(5));
		vector<vector<int> > tmp(n,vector<int>(5));
		for(int i=0;i<n;i++) {
			for(int j=0;j<5;j++) {
				cin>>mat[i][j];
			}
		}
		int ans = INT_MIN;
		for(int i=0;i+5<=n;i++) {
			set_prob(tmp,mat,dp);
			for(int x=i;x<i+5;x++) {
				for(int y=0;y<5;y++) {
					if(tmp[x][y]==-1) {
						tmp[x][y] = 0;
					}
				}
			}
			int option1 = solve(dp,tmp,n-1,1);
			int option2 = solve(dp,tmp,n-1,2);
			int option3 = solve(dp,tmp,n-1,3);
			ans = max(max(ans,option1),max(option2,option3));
		}
		cout<<ans<<"\n";
	}
	return 0;
}