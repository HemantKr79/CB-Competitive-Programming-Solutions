#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

void update(int *BIT,int i,int num,int n) {
    while(i<=n) {
        BIT[i] += num;
        i += (i&(-i));
    }
}

int query(int *BIT,int i) {
    int ans = 0;
    while(i>0) {
        ans += BIT[i];
        i -= i&(-i);
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int *BIT = new int[n+1]();
        int *a = new int[n+1]();
        set<int> s;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            s.insert(a[i]);
        }
        int cnt = 1;
        unordered_map<int,int> m;
        while(!s.empty()) {
            if(m.find(*s.begin())==m.end()) {
                m[*s.begin()] = cnt;
                cnt++;
            }
            s.erase(*s.begin());
        }
        for(int i=1;i<=n;i++) {
            a[i] = m[a[i]];
        }
        long long ans = 0;
        for(int j=n;j>=1;j--) {
            ans += query(BIT,a[j]-1);
            update(BIT,a[j],1,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
