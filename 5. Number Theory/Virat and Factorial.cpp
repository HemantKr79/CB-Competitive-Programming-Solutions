#include<iostream>
using namespace std;

#define MOD 1000000007
#define ll long long

ll modular_factorial(ll n) {
    ll ans = 1;
    while(n>0) {
        ans = (ans*n)%MOD;
        n--;
    }
    return ans;
}

ll fast_modulo_exponentiation(ll n,ll p) {
    ll ans = 1;
    while(p>0) {
        if(p&1)
            ans = (ans*n)%MOD;
        n = (n*n)%MOD;
        p = p>>1;
    }
    return ans;
}

ll inverse_modulo_factorial(ll n) {
    ll ans = 1;
    while(n>0) {
        ans = (ans*fast_modulo_exponentiation(n,MOD-2))%MOD;
        n--;
    }
    return ans;
}

ll nCr(ll n,ll r) {
    ll ans = modular_factorial(n);
    ll n_r_inverse = inverse_modulo_factorial(n-r);
    ll r_inverse = inverse_modulo_factorial(r);
    ans = (ans*n_r_inverse)%MOD;
    ans = (ans*r_inverse)%MOD;
    return ans; 
}

int main() {
    ll n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
    return 0;
}