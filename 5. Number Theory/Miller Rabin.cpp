#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

ll modular_multiplicatin(ll a,ll b,ll n) {
	ll res = 0;
	while(b) {
		if(b&1ll) {
			res += a;
		}
		a *= 2;
		b /= 2;
		res %= n;
		a %= n;
	}
	return res;
}

ll modular_exponentiation(ll a,ll b,ll n) {
	ll res = 1;
	while(b) {
		if(b&1ll) {
			res = modular_multiplicatin(res,a,n);
		}
		a = modular_multiplicatin(a,a,n);
		a %= n;
		b /= 2;
	}
	return res;
}

bool miller_rabin(ll n) {
	if(n==1) {
		return false;
	}
	if(n==2) {
		return true;
	}
	if(n%2==0) {
		return false;
	}
	ll d = n-1;
	ll s=0;
	while(d%2==0) {
		s++;
		d /= 2;
	}
	vector<ll> a({2,3,5,7,11,13,17,19,23});
	for(ll i=0;i<a.size();i++) {
		if(a[i]>n-2) {
			continue;
		}
		ll ad = modular_exponentiation(a[i],d,n);
		if(ad%n==1) {
			continue;
		}
		bool prime = false;
		for(ll r=0;r<=s-1;r++) {
			ll rr = modular_exponentiation(2,r,n);
			ll ard = modular_exponentiation(ad,rr,n);
			if(ard%n == n-1) {
				prime = true;
				break;
			}
		}
		if(prime==false) {
			return false;
		}
	}
	return true;
}

int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<=n;i++) {
	    cout<<i<<": ";
		if(miller_rabin(i)) {
			cout<<"Prime"<<endl;
		}
		else {
			cout<<"Not Prime"<<endl;
		}
	}
	return 0;
}