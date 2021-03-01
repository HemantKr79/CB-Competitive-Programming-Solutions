#include<iostream>
#include<climits>
using namespace std;

#define ll long long

ll solve(int *a,int s,int e) {
	if(s>e) {
		return LLONG_MIN;
	}
	if(s==e) {
		return a[s];
	}
	int m = (s+e)/2;
	ll leftAns = solve(a,s,m);
	ll rightAns = solve(a,m+1,e);
	ll suffixSum = LLONG_MIN;
	ll prefixSum = LLONG_MIN;
	ll sum = 0;
	for(int x=m;x>=s;x--) {
		sum += a[x];
		suffixSum = max(suffixSum,sum);
	}
	sum = 0;
	for(int x=m+1;x<=e;x++) {
		sum += a[x];
		prefixSum = max(prefixSum,sum);
	}
	return max(prefixSum+suffixSum,max(leftAns,rightAns));
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a = new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		ll ans = solve(a,0,n-1);
		cout<<ans<<endl;
	}
	return 0;
}