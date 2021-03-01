#include <iostream>
using namespace std;

#define MOD 1000000007
#define ll long long

int main() {
    	int x;
	cin>>x;
	ll p[x+1];
	p[0] = 0;
	ll divisors = 1;
	for(int i=1;i<=x;i++) {
		cin>>p[i];
		divisors = (divisors*(p[i]+1))%MOD;
	}
	for(int i=1;i<=x;i++) {	
          p[i] = (divisors*p[i])%MOD;
          p[i] = (p[i]*500000004)%MOD;
	}
	ll ans = 1;
	for(int i=1;i<=x;i++) {
		ans = (ans*(p[i]+1))%MOD;
	}
	cout<<ans;
    	return 0;
}