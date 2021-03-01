#include <iostream>
using namespace std;

#define ll long long

ll x,y,gcd;

ll find_gcd(ll a,ll b) {
    if(b==0) {
        return a;
    }
    return find_gcd(b,a%b);
}

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

ll modInverse(ll n,ll m) {
    extended_euclidian(n,m);
    return (x+m)%m;
}


int main() {
    ll n,p,w,d;
    cin>>n;
    cin>>p;
    cin>>w;
    cin>>d;
    ll g = find_gcd(w,d);
    if((p%g)!=0) {
        cout<<-1;
        return 0;
    }
    if(n*w < p) {
        cout<<-1;
        return 0;
    }
    w = w/g;
    d = d/g;
    p = p/g;
    ll y = ((p%w)*modInverse(d,w))%w;
    ll x = (p - y*d)/w;
    if(x+y>n) {
        cout<<-1;
        return 0;
    }
    if(x<0) {
        cout<<-1;
        return 0;
    }
    ll z = (n-x-y);
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
