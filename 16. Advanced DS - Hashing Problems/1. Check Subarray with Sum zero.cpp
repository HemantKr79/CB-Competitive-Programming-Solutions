#include <iostream>
#include <unordered_set>
using namespace std;

bool subarraywith0Sum(int *arr,int n) {
    int pre = 0;
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        pre += arr[i];
        if(pre==0 || s.find(pre)!=s.end()) {
            return true;
        }
        else {
            s.insert(pre);
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<subarraywith0Sum(arr,n);
}