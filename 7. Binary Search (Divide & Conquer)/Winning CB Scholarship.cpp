#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll s = 0;
    ll e = n;
    ll ans = 0;
    while(s<=e) {
        ll mid = (s+e)/2;
        ll total_coupons = m + y*(n-mid);
        if(total_coupons >= mid*x) {
            ans = max(ans,mid);
            s = mid+1;
        }
        else {
            e = mid-1;
        }
    }
    cout<<ans;
    return 0;
}
