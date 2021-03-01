#include<iostream>
using namespace std;

#define ll long long
ll x,y,gcd;
ll MOD = 1000000007;

void extended_euclidian(ll n,ll m) {
    if(m==0) {
        x = 1;
        y = 0;
        gcd = n;
        return;
    }
    extended_euclidian(m,n%m);
    ll cx = y;
    ll cy = x - (n/m)*y;
    x = cx;
    y = cy;
}

void print_inverse(ll n) {
    extended_euclidian(n,MOD);
    cout<<(x+MOD)%MOD;
}

int main() {
    ll n;
    cin>>n;
    print_inverse(n);
    return 0;
}