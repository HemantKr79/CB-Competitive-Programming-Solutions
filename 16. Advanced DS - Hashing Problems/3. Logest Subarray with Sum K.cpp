#include <iostream>
#include <unordered_map>
using namespace std;

int lensubarraywithkSum(int *arr,int n,int k) {
    int pre = 0;
    unordered_map<int,int> m;
    int len = 0;
    for(int i=0;i<n;i++) {
        pre += arr[i];
        if(pre==k) {
            len = max(len,i+1);
        }
        else if(m.find(pre-k)!=m.end()) {
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
    int k;
    cin>>k;
    cout<<lensubarraywithkSum(arr,n,k);
    delete [] arr;
    return 0;
}
