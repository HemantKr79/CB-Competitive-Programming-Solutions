#include <iostream>
using namespace std;

#define int long long int

int poly_hash_string(string s) {
    int hash = 0;
    int p = 31, m = 1e9 + 7;
    int p_power = 1;
    for(int i=0;i<s.size();i++) {
        hash += (s[i] - 'a' + 1)*p_power;
        p_power *= p;
        hash %= m;
        p_power %= m;
    }
    return hash;
}

int32_t main() {
    string s = "ababab";
    cout<<poly_hash_string(s);
    return 0;
}
