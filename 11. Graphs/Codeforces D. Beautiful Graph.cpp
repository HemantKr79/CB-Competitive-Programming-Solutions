#include <iostream>
#include <vector>
using namespace std;

#define MOD 998244353
#define int long long
int gcol[3];

bool is_bypertite(int cur,vector<int> *gr,vector<int> &col,int c) {
    col[cur] = c;
    gcol[c]++;
    for(auto nbr : gr[cur]) {
        if(col[nbr]==0) {
            if(!is_bypertite(nbr,gr,col,3-c)) {
                return false;
            }
        }
        else if(col[nbr]==c) {
            return false;
        }
    }
    return true;
}

int power(int b,int p) {
    int ans = 1;
    int tmp = b;
    while(p>0) {
        if(p&1) {
            ans = (ans*tmp)%MOD;
        }
        tmp = (tmp*tmp)%MOD;
        p = p>>1;
    }
    return ans;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--) {
        gcol[0] = gcol[1] = gcol[2] = 0;
        int n,m,x,y;
        cin>>n>>m;
        vector<int> gr[n+1];
        vector<int> col(n+1,0);
        for(int i=0;i<m;i++) {
            cin>>x>>y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        bool bypertite = true;
        int ans = 1;
        for(int i=1;i<=n;i++) {
            if(col[i]==0) {
                gcol[1] = gcol[2] = 0;
                bypertite = bypertite&&(is_bypertite(i,gr,col,1));
                if(!bypertite) {
                    break;
                }
                ans = (ans*((power(2,gcol[1]) + power(2,gcol[2])%MOD)))%MOD;
            }
        }
        if(!bypertite) {
            cout<<0<<endl;
        }
        else {
            cout<<ans<<endl;
        }
    }
    return 0;
}
