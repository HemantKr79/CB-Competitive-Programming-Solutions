#include <iostream>
using namespace std;

#define ll long long

bool isPossible(ll *trees,ll n,ll mid,ll m) {
    ll total = 0;
    for(int i=0;i<n;i++) {
        if(trees[i]>mid) {
            total += (trees[i]-mid);
            if(total >= m) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n,m;
    cin>>n>>m;
    ll *trees = new ll[n];
    cin>>trees[0];
    ll s = 0;
    ll e = trees[0];
    for(ll i=1;i<n;i++) {
        cin>>trees[i];
        e = max(e,trees[i]);
    }
    ll ans = s;
    while(s<=e) {
        ll mid = (s+e)/2;
        if(isPossible(trees,n,mid,m)) {
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
