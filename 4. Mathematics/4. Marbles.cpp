#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

void printPermutation(ll n,ll r) {
	ll num = 1;
	ll deno = 1;
	r = max(n-r,r);
	if(r != 0) {
		while(r>0) {
			num *= n;
			deno *= r;
			ll gcd = __gcd(num,deno);
			num = num/gcd;
			deno = deno/gcd;
			n--;
			r--;
		}
	}
	else {
		num = 1;
	}
	cout<<num<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n,k;
		cin>>n;
		cin>>k;
		printPermutation(n-1,k-1);
	}
	return 0;
}