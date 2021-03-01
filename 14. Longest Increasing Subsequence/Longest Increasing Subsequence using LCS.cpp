#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LCS(vector<int> &a,vector<int> &b,int n) {
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    cout<<LCS(a,b,n);
    return 0;
}