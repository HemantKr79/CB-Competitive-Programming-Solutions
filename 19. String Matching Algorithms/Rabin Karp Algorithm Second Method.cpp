


#include <iostream>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;
const int p = 31;

int powr(int a,int b) {
    int res = 1;
    while(b>0) {
        if(b&1ll) {
            res *= a;
            res %= mod;
        }
        a *= a;
        b = b>>1;
        a %= mod;
    }
    return res;
}

int poly_hash_string(string s) {
    int res = 0;
    int p_power = 1;
    for(int i=0;i<s.length();i++) {
        res = (res + (s[i] - 'a' + 1)*p_power)%mod;
        p_power *= p;
        p_power %= mod;
    }
    return res;
}

int32_t main() {
    string text = "ababab";
    string pat = "aba";
    int n = text.length();
    int m = pat.length();
    int pat_hash = poly_hash_string(pat);
    int *prefix = new int[n];
    for(int i=0;i<n;i++) {
        prefix[i] = (text[i]-'a'+1)*powr(p,i);
    }
    for(int i=1;i<n;i++) {
        prefix[i] = (prefix[i-1] + prefix[i])%mod;
    }
    for(int i=0;i+m<=n;i++) {
        int new_hash = prefix[i+m-1];
        if(i-1>=0) {
            new_hash -= prefix[i-1];
        }
        new_hash += mod;
        new_hash %= mod;
        if(new_hash==(pat_hash*powr(p,i))%mod) {
            cout<<i<<endl;
        }
    }
    return 0;
}
