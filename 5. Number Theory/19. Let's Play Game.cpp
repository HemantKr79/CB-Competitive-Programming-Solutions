#include<iostream>
#include<bitset>
using namespace std;

#define ll long long

bitset<501> b;

void seive() {
	b.set();
	b[0] = b[1] = 0;
	b[2] = 1;
	for(ll i=4;i<501;i+=2) {
		b[i] = 0;
	}
	for(ll i=3;i<501;i+=2) {
		if(b[i]==1) {
			for(ll j=i*i;j<501;j+=i) {
				b[j] = 0;
			}
		}
	}
}

ll solve(ll n) {
	ll dp[n+1];
	dp[1] = 0;
	dp[2] = 1;
	for(ll i=3;i<=n;i++) {
		if(b[i]==1) {
			dp[i] = dp[i-1]*2;
		}
		else {
			dp[i] = dp[i-1];
		}
	}
	ll ans = 0;
	for(ll i=1;i<=n;i++) {
		ans += dp[i];
	}
	return ans;
}

int main() {
	seive();
	ll n;
	cin>>n;
	ll ans = solve(n);
	cout<<ans;
	return 0;
}