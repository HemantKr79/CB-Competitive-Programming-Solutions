#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define RANGE 100000
#define ll long long

bitset<RANGE+1> b;
vector<int> primes;

void seive() {
    b.set();
    for(int i=2;i<=RANGE;i+=2) {
        b[i] = 0;
    }
    primes.push_back(2);
    for(int i=3;i<=RANGE;i+=2) {
        if(b[i]==1) {
            primes.push_back(i);
            for(ll j=i*(ll)i;j<=RANGE;j+=i) {
                b[j] = 0;
            }
        }
    }
    b[0] = b[1] = 0;
    b[2] = 1;
}

int main() {
    seive();
    int t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>m;
        cin>>n;
        int *nums = new int[n-m+1];
        for(int i=0;i<n-m+1;i++) {
            nums[i] = 1;
        }
        for(auto x : primes) {
            if(x*(long long)x>n) {
                break;
            }
            ll start = (m/x)*x;
            if(x>=m && x<=n) {
                start = 2*x;
            }
            for(ll i=start;i<=n;i+=x) {
                nums[i-m] = 0;
            }
        }
        for(int i=0;i<n-m+1;i++) {
            if(nums[i]==1 && (i+m)!=1) {
                cout<<i+m<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
