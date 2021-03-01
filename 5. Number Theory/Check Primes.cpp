#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long

bitset<10000005> b;
vector<ll> primes;

void steve() {
    b.set();
    for(int i=2;i<10000000;i+=2) {
        b[i] = 0;
    }
    primes.push_back(2);
    for(ll i=3;i<10000000;i+=2) {
        if(b[i]==1) {
            primes.push_back(i);
            for(ll j=(i*i);j<10000000;j+=i) {
                b[j] = 0;
            }
        }
    }
    b[0] = b[1] = 0;
    b[2] = 1;
}

bool check(ll n) {
    steve();
    if(n<10000000) {
        return b[n]==1;
    }
    for(int i=0;primes[i]*primes[i]<n;i++) {
        if(n%primes[i]==0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n;
    cin>>n;
    if(check(n)) {
        cout<<"Prime";
    }
    else {
        cout<<"Not Prime";
    }
    return 0;
}
