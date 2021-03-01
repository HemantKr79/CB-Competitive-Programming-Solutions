#include <iostream>
using namespace std;

struct activity {
    int a,b,c;
};

int solve(activity *arr,int n) {
    int dp[n+1][3];
    dp[1][0] = arr[1].a;
    dp[1][1] = arr[1].b;
    dp[1][2] = arr[1].c;
    for(int i=2;i<=n;i++) {
        dp[i][0] = arr[i].a + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = arr[i].b + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = arr[i].c + max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[n][0],max(dp[n][1],dp[n][2]));
}

int main() {
	int n;
	cin>>n;
	activity *arr = new activity[n+1];
	for(int i=1;i<=n;i++) {
	    cin>>arr[i].a>>arr[i].b>>arr[i].c;
	}
	cout<<solve(arr,n);
	return 0;
}
