#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long
bitset<100005> b;
vector<int> primes;

void seive() {
    b.set();
    b[0] = b[1] = 0;
    primes.push_back(2);
    for(int i=4;i<=100000;i+=2) {
        b[i] = 0;
    }
    for(ll i=3;i<=100000;i+=2) {
        if(b[i]==1) {
            primes.push_back(i);
        }
        for(ll j=i*i;j<=100000;j+=i) {
            b[j] = 0;
        }
    }
}

vector<pair<ll,int> > find_factors(ll n) {
    vector<pair<ll,int> > factors;
    for(auto x : primes) {
        if(x*x > n) {
            break;
        }
        if(n%x == 0) {
            int cnt = 0;
            while(n%x==0) {
                cnt++;
                n = n/x;
            }
            factors.push_back(make_pair(x,cnt));
        }
    }
    if(n!=1) {
        factors.push_back(make_pair(n,1));
    }
    return factors;
}

int main() {
    seive();
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<pair<ll,int> > factors = find_factors(n);
        if(factors.size()==0) {
            cout<<"NO"<<endl;
            continue;
        }
        else if(factors.size()==1) {
            if(factors[0].second < 6) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
                ll f1 = factors[0].first;
                ll f2 = f1*f1;
                ll f3 = n/(f1*f2);
                cout<<f1<<" "<<f2<<" "<<f3<<endl;
            }
            continue;
        }
        else {
            ll f1 = factors[0].first;
            ll f2 = factors[1].first;
            ll f3 = (n)/(f1*f2);
            if(f3==f1 || f3==f2 || f3==1) {
                cout<<"NO"<<endl;
            }
            else {
                cout<<"YES"<<endl;
                cout<<f1<<" "<<f2<<" "<<f3<<endl;
            }
            continue;
        }
    }
    return 0;
}
