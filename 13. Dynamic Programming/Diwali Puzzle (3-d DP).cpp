#include <iostream>
using namespace std;

#define int long long
#define MOD 1000003
int dp[105][2][105];
int n,k;

void set_dp() {
    for(int i=0;i<105;i++) {
        for(int j=0;j<2;j++) {
            for(int l=0;l<105;l++) {
                dp[i][j][l] = -1;
            }
        }
    }
}

int f(int index,int prev,int cur) {
    if(index==n) {
        if(cur==k) {
            return 1;
        }
        return 0;
    }
    if(dp[index][prev][cur]!=-1) {
        return dp[index][prev][cur];
    }
    int ans = 0;
    if(prev==1) {
        ans = ans + f(index+1,1,cur+1);
    }
    else {
        ans = ans + f(index+1,1,cur);
    }
    ans %= MOD;
    ans = ans + f(index+1,0,cur);
    ans %= MOD;
    dp[index][prev][cur] = ans;
    return ans;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        set_dp();
        cout<<(f(1,0,0)+f(1,1,0))%MOD<<endl;
    }
    return 0;
}
