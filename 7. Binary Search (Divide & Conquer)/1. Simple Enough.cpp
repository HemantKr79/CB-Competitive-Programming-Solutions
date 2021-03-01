#include<iostream>
using namespace std;

#define int long long

int cnt_bits(int n) {
	if(n==1 || n==0) {
		return 1;
	}
	int ans = 2*cnt_bits(n/2);
	return ans+1;
}

int solve(int n,int s,int e,int l,int r) {
	if(e<s || l>e || r<s) {
		return 0;
	}
	int ans = 0;
	int m = (s+e)/2;
	if(l<=m && m<=r) {
		ans += n%2;
	}
	ans += solve(n/2,s,m-1,l,r);
	ans += solve(n/2,m+1,e,l,r);
	return ans;
}

int32_t main() {
	int n,l,r;
	cin>>n>>l>>r;
	int total_bits = cnt_bits(n);
	cout<<solve(n,1,total_bits,l,r);
	return 0;
}