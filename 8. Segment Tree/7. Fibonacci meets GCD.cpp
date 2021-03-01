#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007
#define ll long long

ll gcd(ll a,ll b) {
    if(a==-1) {
        return b;
    }
    if(b==-1) {
        return a;
    }
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

vector<vector<ll> > multiply(vector<vector<ll> > &m1,vector<vector<ll> > &m2) {
    vector<vector<ll> > res(3,vector<ll>(3));
    for(ll i=1;i<=2;i++) {
        for(ll j=1;j<=2;j++) {
            res[i][j] = 0;
            for(ll x=1;x<=2;x++) {
                res[i][j] = (res[i][j] + (m1[i][x]*m2[x][j])%MOD)%MOD;
            }
        }
    }
    return res;
}

vector<vector<ll> > power(vector<vector<ll> > &transformation,ll p) {
    vector<vector<ll> > res(3,vector<ll>(3));
    res[1][1] = 1;
    res[1][2] = 0;
    res[2][1] = 0;
    res[2][2] = 1;
    vector<vector<ll> > tmp = transformation;
    while(p>0) {
        if(p&1) {
            res = multiply(res,tmp);
        }
        p = p>>1;
        tmp = multiply(tmp,tmp);
    }
    return res;
}

ll fibo(ll n) {
    if(n==1 || n==2) {
        return 1;
    }
    vector<vector<ll> > transformation(3,vector<ll>(3));
    transformation[1][1] = 0;
    transformation[1][2] = 1;
    transformation[2][1] = 1;
    transformation[2][2] = 1;
    vector<ll> F1(3);
    F1[1] = 1;
    F1[2] = 1;
    transformation = power(transformation,n-1);
    ll ans = 0;
    for(ll i=1;i<=2;i++) {
        ans = (ans + transformation[1][i]*F1[i])%MOD;
    }
    return ans;
}

void build_tree(ll *a,ll *tree,ll s,ll e,ll index) {
    if(s==e) {
        tree[index] = a[s];
        return;
    }
    ll m = (s+e)/2;
    build_tree(a,tree,s,m,2*index);
    build_tree(a,tree,m+1,e,2*index+1);
    tree[index] = gcd(tree[2*index],tree[2*index+1]);
}

ll query(ll *tree,ll ss,ll se,ll qs,ll qe,ll index) {
    if(qe<ss || qs>se) {
        return -1;
    }
    if(qs<=ss && se<=qe) {
        return tree[index];
    }
    ll m = (ss+se)/2;
    ll leftAns = query(tree,ss,m,qs,qe,2*index);
    ll rightAns = query(tree,m+1,se,qs,qe,2*index+1);
    return gcd(leftAns,rightAns);
}

int main() {
	ll n,q;
	cin>>n>>q;
	ll *a = new ll[n];
	for(ll i=0;i<n;i++) {
	    cin>>a[i];
	}
	ll *tree = new ll[4*n+1];
	build_tree(a,tree,0,n-1,1);
	while(q--) {
	    ll qs,qe;
	    cin>>qs>>qe;
	    cout<<fibo(query(tree,0,n-1,qs-1,qe-1,1))%MOD<<endl;
	}
	return 0;
}
