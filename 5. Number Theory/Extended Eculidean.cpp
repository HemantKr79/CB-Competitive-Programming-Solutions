#include <iostream>
using namespace std;

int x,y,gcd;

void extended_euclidean(int a,int b) {
    if(b==0) {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    extended_euclidean(b,a%b);
    int cx = y;
    int cy = x - (a/b)*y;
    x = cx;
    y = cy;
}

int main() {
    extended_euclidean(18,30);
    cout<<"18*"<<x<<" + 30*"<<y<<" = "<<gcd;
    return 0;
}
