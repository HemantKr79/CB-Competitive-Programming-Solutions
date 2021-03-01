#include <iostream>
using namespace std;

void multiply(int *bigInt,int &digits,int i) {
    int carry = 0;
    for(int j=0;j<digits;j++) {
        int mutiplication = bigInt[j]*i + carry;
        bigInt[j] = mutiplication%10;
        carry = mutiplication/10;
    }
    while(carry) {
        bigInt[digits] = carry%10;
        carry = carry/10;
        digits++;
    }
}

void fact(int n) {
    int *bigInt = new int[1000];
    for(int i=0;i<1000;i++) {
        bigInt[i] = 0;
    }
    int digits = 1;
    bigInt[0] = 1;
    for(int i=1;i<=n;i++) {
        multiply(bigInt,digits,i);
    }
    for(int i=digits-1;i>=0;i--) {
        cout<<bigInt[i];
    }
    delete [] bigInt;
}

int main() {
    int n;
    cin>>n;
    fact(n);
    return 0;
}
