#include <iostream>
using namespace std;

#define ll long long

bool isPossible(int *cooks,int l,int p,int m) {
    int remaining_paraths = p;
    for(int cook=0;cook<l;cook++) {
        ll cook_time = cooks[cook];
        ll time = 0;
        while(time + cook_time <= m) {
            remaining_paraths--;
            if(remaining_paraths==0) {
                return true;
            }
            time = time + cook_time;
            cook_time += cooks[cook];
        }
    }
    return false;
}

int main() {
    int p;
    cin>>p;
    int l;
    cin>>l;
    int *cooks = new int[l];
    cin>>cooks[0];
    int fastest_cook = cooks[0];
    for(int i=1;i<l;i++) {
        cin>>cooks[i];
        fastest_cook = min(cooks[i],fastest_cook);
    }
    ll e = 0;
    int tmp = p;
    ll time_taken_by_fastest_cook = fastest_cook;
    while(tmp--) {
        e += time_taken_by_fastest_cook;
        time_taken_by_fastest_cook += fastest_cook;
    }
    ll s = 0;
    int ans = e;
    while(s<=e) {
        int m = (s+e)/2;
        if(isPossible(cooks,l,p,m)) {
            ans = min(ans,m);
            e = m-1;
        }
        else {
            s = m+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
