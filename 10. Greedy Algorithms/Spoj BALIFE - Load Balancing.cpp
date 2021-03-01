#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    while(true) {
        ll n;
        cin>>n;
        if(n==-1) {
            break;
        }
        ll *sum = new ll[n];
        ll s = 0;
        ll num;
        for(ll i=0;i<n;i++) {
            cin>>num;
            s += num;
            sum[i] = s;
        }
        if(s%n!=0) {
            cout<<-1<<endl;
            continue;
        }
        ll load = s/n;
        ll ans = 0;
        for(ll i=0;i<n-1;i++) {
            ll maxLoadLeft = abs( ((i+1)*load) - sum[i] );
            ans = max(ans,maxLoadLeft);
        }
        cout<<ans<<endl;
    }
    return 0;
}
