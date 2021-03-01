#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int cur,vector<int> *gr,vector<int> &dp) {
    if(dp[cur]!=-1) {
        return dp[cur];
    }
    bool isLeaf = true;
    int best = 0;
    for(auto nbr : gr[cur]) {
        isLeaf = false;
        best = max(best,solve(nbr,gr,dp));
    }
    dp[cur] = (isLeaf)?0:1+best;
    return dp[cur];
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> gr[n+1];
	for(int i=0;i<m;i++) {
	    int x,y;
	    cin>>x>>y;
	    gr[x].push_back(y);
	}
	vector<int> dp(n+1,-1);
	for(int i=1;i<=n;i++) {
	    if(dp[i]==-1) {
	        dp[i] = solve(i,gr,dp);
	    }
	}
	cout<<*max_element(dp.begin(),dp.end());
	return 0;
}
