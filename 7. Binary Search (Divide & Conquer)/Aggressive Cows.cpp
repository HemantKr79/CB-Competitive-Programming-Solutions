#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(int *stalls,int min_sep,int n,int c) {
    int last_cow = stalls[0];
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if( (stalls[i]-last_cow) >= min_sep ) {
            last_cow = stalls[i];
            cnt++;
            if(cnt == c) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n,c;
    cin>>n>>c;
    int *stalls = new int[n];
    for(int i=0;i<n;i++) {
        cin>>stalls[i];
    }
    sort(stalls,stalls+n);
    int s = 0;
    int e = stalls[n-1] - stalls[0];
    int ans = 0;
    while(s<=e) {
        int m = (s+e)/2;
        if(canPlace(stalls,m,n,c)) {
            s = m + 1;
            ans = m;
        }
        else {
            e = m - 1;
        }
    }
    cout<<ans;
    return 0;
}
