#include<iostream>
#include<climits>
using namespace std;

#define int long long

void lets_do_it() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int32_t main() {
	lets_do_it();
	int n;
	while(cin>>n) {
	    int col[n+1];
	    for(int i=1;i<=n;i++) {
	        cin>>col[i];
	    }
	    pair<int,int> dp[n+1][n+1];
	    //dp[i][j].first -> smoke  and  dp[i][j].second -> colour of mixture
	    for(int j=1;j<=n;j++) {
	        dp[j][j].first = 0;
	        dp[j][j].second = col[j];
	    }
	    for(int j=2;j<=n;j++) {
	        int r = 1;
	        int c = j;
	        while(c<=n) {
	            int k = r;
	            int answer = INT_MAX;
	            int color = 0;
	            while(k<c) {
	                int tmp = dp[r][k].first+dp[k+1][c].first + dp[r][k].second*dp[k+1][c].second;
	                if(answer > tmp) {
	                    color = dp[r][k].second + dp[k+1][c].second;
	                    color %= 100;
	                    answer = tmp;
	                }
	                ++k;
	            }
	            dp[r][c].first = answer;
	            dp[r][c].second = color;
	            r++;
	            c++;
	        }
	    }
	    cout<<dp[1][n].first<<endl;
	}
	return 0;
}
