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
        a %= mod;
        b = b>>1;
    }
    return res;
}

int inv(int a) {
    return powr(a,mod-2);
}

int poly_hash_string(string s) {
    int hash = 0;
    int p_power = 1;
    for(int i=0;i<s.size();i++) {
        hash += (s[i] - 'a' + 1)*p_power;
        p_power *= p;
        hash %= mod;
        p_power %= mod;
    }
    return hash;
}

int32_t main() {
    string text = "ababab";
    string pat = "aba";
    int n = text.length();
    int m = pat.length();
    int pat_hash = poly_hash_string(pat);
    int text_hash = poly_hash_string(text.substr(0,m));
    if(text_hash==pat_hash) {
        cout<<0<<endl;
    }
    for(int i=1;i+m<=n;i++) {
        int new_hash = text_hash;

        new_hash = (new_hash - (text[i-1] - 'a' + 1) + mod)%mod;

        new_hash = (new_hash * inv(p));
        new_hash %= mod;

        new_hash += (text[i+m-1] - 'a' + 1)*powr(p,m-1);
        new_hash %= mod;

        if(new_hash==pat_hash) {
            cout<<i<<endl;
        }
        text_hash = new_hash;
    }
    return 0;
}
