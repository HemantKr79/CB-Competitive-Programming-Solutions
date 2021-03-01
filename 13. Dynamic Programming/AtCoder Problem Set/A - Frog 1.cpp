#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &h,int n) {
    vector<int> dp(n+1);
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);
    for(int i=3;i<=n;i++) {
        int option1 = dp[i-1] + abs(h[i]-h[i-1]);
        int option2 = dp[i-2] + abs(h[i]-h[i-2]);
        dp[i] = min(option1,option2);
    }
    return dp[n];
}

int main() {
	int n;
	cin>>n;
	vector<int> h(n+1);
	for(int i=1;i<=n;i++) {
	    cin>>h[i];
	}
	cout<<solve(h,n);
	return 0;
}
