#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        string str;
        ll rank;
        ll *cnt = new ll[n+1]();
        for(ll i=0;i<n;i++) {
            cin>>str;
            cin>>rank;
            cnt[rank]++;
        }
        ll badness = 0;
        ll availabe_rank = 1;
        for(ll i=1;i<=n;i++) {
            while(cnt[i]>0) {
                badness += abs(availabe_rank-i);
                cnt[i]--;
                availabe_rank++;
            }
        }
        cout<<badness<<endl;
    }
    return 0;
}
