#include <iostream>
using namespace std;
 
int main() {
    int s = 1;
    int e = 1e6;
    int m;
    string str;
    int ans = 0;
    while(s<=e) {
        m = (s+e)/2;
        cout<<m<<endl;
        cin>>str;
        if(str=="<") {
            ans = m;
            e = m-1;
        }
        else {
            s = m+1;
        }
    }
    if(ans==0) {
        cout<<"! "<<ans<<endl;
    }
    else {
        cout<<"! "<<ans-1<<endl;
    }
    return 0;
}