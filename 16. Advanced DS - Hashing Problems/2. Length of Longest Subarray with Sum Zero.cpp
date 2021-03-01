#include <iostream>
#include <unordered_map>
using namespace std;

int lensubarraywith0Sum(int *arr,int n) {
    int pre = 0;
    unordered_map<int,int> m;
    int len = 0;
    for(int i=0;i<n;i++) {
        pre += arr[i];
        if(pre==0) {
            len = max(len,i+1);
        }
        else if(m.find(pre)!=m.end()) {
            len = max(len,i-m[pre]);
        }
        else {
            m[pre] = i;
        }
    }
    return len;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<lensubarraywith0Sum(arr,n);
    delete [] arr;
    return 0;
}