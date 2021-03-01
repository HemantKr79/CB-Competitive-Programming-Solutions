#include <iostream>
using namespace std;

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpelling(int n) {
    if(n==0) {
        return;
    }
    printSpelling(n/10);
    cout<<words[n%10]<<" ";
}

int main() {
    int n;
    cin>>n;
    printSpelling(n);
    cout<<endl;
    return 0;
}
