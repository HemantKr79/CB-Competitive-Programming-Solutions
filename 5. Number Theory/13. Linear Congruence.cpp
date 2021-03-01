#include<iostream>
using namespace std;

#define ll long long
ll x,y,gcd;

void mulitplicative_modulo_inverse_helper(ll a,ll b) {
	if(b==0) {
		x = 1;
		y = 0;
		gcd = a;
		return;
	}
	mulitplicative_modulo_inverse_helper(b,a%b);
	ll cx = y;
	ll cy = x - (a/b)*y;
	x = cx;
	y = cy;
}

ll mulitplicative_modulo_inverse(ll a,ll b) {
	mulitplicative_modulo_inverse_helper(a,b);
	return (x+b)%b;
}

int main() {
	ll k;
	cin>>k;
	ll *num = new ll[k];
	ll *rem = new ll[k];
	long long int pp = 1;
	for(ll i=0;i<k;i++) {
		cin>>num[i];
		pp *= num[i];
	}
	for(ll i=0;i<k;i++) {
		cin>>rem[i];
	}
	ll ans = 0;
	for(ll i=0;i<k;i++) {
		ll pp_i = pp/num[i];
		ans += (rem[i]*pp_i*mulitplicative_modulo_inverse(pp_i,num[i]))%pp;
	}
	cout<<ans%pp;
	return 0;
}