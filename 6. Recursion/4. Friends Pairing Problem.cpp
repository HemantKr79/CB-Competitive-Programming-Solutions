#include<iostream>
using namespace std;

#define ll long long

ll findWays(ll n) {
	if(n<=1) {
		return 1;
	}
	return (findWays(n-1) + (n-1)*findWays(n-2));
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		ll n;
		cin>>n;
		cout<<findWays(n)<<endl;
	}
	return 0;
}