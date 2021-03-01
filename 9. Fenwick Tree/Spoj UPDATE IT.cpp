#include <iostream>
using namespace std;

#define ll long long

void update(ll *BIT,ll i,ll val,ll n) {
    while(i<=n) {
        BIT[i] += val;
        i += i&(-i);
    }
}

ll query(ll *BIT,ll i) {
    ll ans = 0;
    while(i>0) {
        ans += BIT[i];
        i -= i&(-i);
    }
    return ans;
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n,u;
        cin>>n>>u;
        ll *BIT = new ll[n+1]();
        while(u--) {
            ll l,r,val;
            cin>>l>>r>>val;
            update(BIT,l+1,val,n);
            update(BIT,r+2,-val,n);
        }
        ll q;
        cin>>q;
        while(q--) {
            ll i;
            cin>>i;
            cout<<query(BIT,i+1)<<endl;
        }
    }
    return 0;
}
