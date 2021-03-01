#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		ll *a = new ll[n];
		for(ll i=0;i<n;i++) {
			cin>>a[i];
		}
		sort(a,a+n);
		ll maxDifference = 0;
		ll i=0,j=n-1;
		while(i<j) {
			maxDifference += abs(a[j]-a[i]);
			i++;
			j--;
		}
		ll minDifference = 0;
		i = 0;
		while(i<n-1) {
			minDifference += abs(a[i+1]-a[i]);
			i += 2;
		}
		cout<<minDifference<<" "<<maxDifference<<endl;
	}
	return 0;
}