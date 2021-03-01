#include<iostream>
using namespace std;

#define MOD 1000000007

int findWays(int n,int m) {
	if(m>n) {
		return 1;
	}
	int *ans = new int[n+1];
	for(int i=0;i<m;i++) {
		ans[i] = 1;
	}
	for(int i=m;i<=n;i++) {
		ans[i] = (ans[i-1] + ans[i-m])%MOD;
	}
	int finalAns = ans[n];
	delete [] ans;
	return finalAns;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		cout<<findWays(n,m)<<endl;
	}
	return 0;
}