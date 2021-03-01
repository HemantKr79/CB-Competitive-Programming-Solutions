#include <iostream>
using namespace std;

int main() {
    cout<<"? ";
    for(int i=1;i<=100;i++) {
        cout<<i<<" ";
    }
    cout<<endl;
    int ans;
    cin>>ans;
    int mask = -1;
    mask = mask<<7;
    ans = ans&mask;
    int x = ans;
    cout<<"? ";
    for(int i=1;i<=100;i++) {
        cout<<(i<<7)<<" ";
    }
    cout<<endl;
    cin>>ans;
    mask = (-1)<<7;
    mask = ~(mask);
    ans = ans&mask;
    x |= ans;
    cout<<"! "<<x<<endl;
    return 0;
}
