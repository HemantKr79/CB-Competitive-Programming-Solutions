#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll p;

vector<vector<ll> > multiply(vector<vector<ll> > m1, vector<vector<ll> > m2,int k) {
    vector<vector<ll> > res(k+2,vector<ll>(k+2));
    for(int i=1;i<=k+1;i++) {
        for(int j=1;j<=k+1;j++) {
            res[i][j] = 0;
            for(int x=1;x<=k+1;x++) {
                res[i][j] = (res[i][j] + (m1[i][x]*m2[x][j])%p)%p;
            }
        }
    }
    return res;
}

vector<vector<ll> > power(vector<vector<ll> > transformation,ll n,int k) {
    if(n==1) {
        return transformation;
    }
    if(n&1) {
        vector<vector<ll> > ans = multiply(transformation,power(transformation,n-1,k),k);
        return ans;
    }
    vector<vector<ll> > ans = power(transformation,n/2,k);
    ans = multiply(ans,ans,k);
    return ans;
}

ll solve(vector<ll> &b,vector<ll> &c,ll n,int k) {
    if(n<=k) {
        ll ans = 0;
        for(int i=0;i<n;i++) {
            ans += b[i];
        }
        return ans;
    }
    vector<ll> F1(k+2);
    ll s = 0;
    for(int i=0;i<k;i++) {
        s += b[i];
    }
    F1[1] = s;
    for(int i=2;i<=k+1;i++) {
        F1[i] = b[i-2];
    }
    vector<vector<ll> > transformation(k+2,vector<ll>(k+2));
    for(int i=1;i<=k+1;i++) {
        for(int j=1;j<=k+1;j++) {
            if(i==1) {
                if(j==1) {
                    transformation[i][j] = 1;
                }
                else {
                    transformation[i][j] = c[k-j+1];
                }
            }
            else if(i==k+1) {
                if(j==1) {
                    transformation[i][j] = 0;
                }
                else {
                    transformation[i][j] = c[k-j+1];
                }
            }
            else {
                if(j==i+1) {
                    transformation[i][j] = 1;
                }
                else {
                    transformation[i][j] = 0;
                }
            }
        }
    }
    vector<vector<ll> > T = power(transformation,n-k,k);
    ll ans = 0;
    for(int i=1;i<=k+1;i++) {
        ans = (ans + (T[1][i]*F1[i])%p)%p;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    ll num;
    while(t--) {
        int k;
        cin>>k;
        vector<ll> b;
        vector<ll> c;
        for(int i=0;i<k;i++) {
            cin>>num;
            b.push_back(num);
        }
        for(int i=0;i<k;i++) {
            cin>>num;
            c.push_back(num);
        }
        ll m,n;
        cin>>m;
        cin>>n;
        cin>>p;
        ll sumUptoM = solve(b,c,m-1,k);
        ll sumUptoN = solve(b,c,n,k);
        cout<<((sumUptoN-sumUptoM)%p+p)%p<<endl;
    }
    return 0;
}
