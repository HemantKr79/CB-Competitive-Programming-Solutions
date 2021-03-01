#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n<=1) {
        cout<<0;
        return 0;
    }
    int *factors = new int[n+1] ();
    factors[0] = 0;
    factors[1] = 0;
    for(int i=2;i<=n;i++) {
        if(factors[i]==0) {
            for(int j=2*i;j<=n;j+=i) {
                factors[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(factors[i]==2) {
            ans += 1;
        }
    }
    cout<<ans;
    delete [] factors;
    return 0;
}
