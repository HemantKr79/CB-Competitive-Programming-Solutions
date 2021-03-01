#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector<bool> dp(k+1,false);
	vector<int> moves(n);
	for(int i=0;i<n;i++) {
	    cin>>moves[i];
	}
	for(int i=1;i<=k;i++) {
	    for(auto m : moves) {
	        if(i-m>=0 && !dp[i-m]) {
	            dp[i] = true;
	            break;
	        }
	    }
	}
	if(dp[k]) {
	    cout<<"First";
	}
	else {
	    cout<<"Second";
	}
	return 0;
}
