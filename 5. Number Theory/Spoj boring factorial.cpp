#include<iostream>
using namespace std;

#define ll long long

ll mulitplicative_modulo_inverse(ll a,ll p,ll mod) {
    ll ans = 1;
    ll tmp = a;
    while(p>0) {
        if(p&1) {
            ans = (ans*tmp)%mod;
        }
        tmp = (tmp*tmp)%mod;
        p = p>>1;
    }
    return ans;
}

ll compute(ll n,ll p) {
    ll ans = -1;
    for(ll i=(n+1);i<=(p-1);i++) {
        ans = ans*mulitplicative_modulo_inverse(i,p-2,p);
        ans = ans%p;
    }
    return ans+p;
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n,p;
        cin>>n>>p;
        if(p<=n) {
            cout<<0<<endl;
        }
        else {
            cout<<compute(n,p)<<endl;
        }
    }
}