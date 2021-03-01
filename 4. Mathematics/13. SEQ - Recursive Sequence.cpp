#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MOD 1000000000

vector<vector<ll> > multiply(vector<vector<ll> > m1, vector<vector<ll> > m2,int k) {
    vector<vector<ll> > res(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            res[i][j] = 0;
            for(int x=1;x<=k;x++) {
                res[i][j] = (res[i][j] + (m1[i][x]*m2[x][j])%MOD)%MOD;
            }
        }
    }
    return res;
}

vector<vector<ll> > power(vector<vector<ll> > tranformation,int n,int k) {
    if(n==1) {
        return tranformation;
    }
    if(n&1) {
        return multiply(tranformation,power(tranformation,n-1,k),k);
    }
    vector<vector<ll> > temp = power(tranformation,n/2,k);
    return multiply(temp,temp,k);
}

ll solve(vector<ll> &b,vector<ll> &c,int k,int n) {
    if(n<=k) {
        return b[n-1];
    }
    vector<ll> F1(k+1);
    for(int i=1;i<=k;i++) {
        F1[i] = b[i-1];
    }
    vector<vector<ll> > tranformation(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            if(i<k) {
                if(j==i+1) {
                    tranformation[i][j] = 1;
                }
                else {
                    tranformation[i][j] = 0;
                }
            }
            else {
                tranformation[i][j] = c[k-j];
            }
        }
    }
    vector<vector<ll> > T = power(tranformation,n-1,k);
    ll ans = 0;
    for(int i=1;i<=k;i++) {
        ans = (ans + (T[1][i]*F1[i])%MOD)%MOD;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>k;
        vector<ll> b;
        vector<ll> c;
        ll temp;
        for(int i=0;i<k;i++) {
            cin>>temp;
            b.push_back(temp);
        }
        for(int i=0;i<k;i++) {
            cin>>temp;
            c.push_back(temp);
        }
        int n;
        cin>>n;
        ll ans = solve(b,c,k,n);
        cout<<ans<<endl;
    }
    return 0;
}
