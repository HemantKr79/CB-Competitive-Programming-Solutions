#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        double ans = 0;
        int n;
        cin>>n;
        double temp = n;
        while(temp>0) {
            ans += (double)(1/(1.0*temp));
            temp -= 1;
        }
        ans = ans*(1.0*n);
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
