#include <iostream>
#include <unordered_map>
using namespace std;

int lenLongestConsecutiveSubseq(int *arr,int n) {
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        if(m.find(arr[i])!=m.end()) {
            continue;
        }
        bool b1 = m.find(arr[i]-1)==m.end();
        bool b2 = m.find(arr[i]+1)==m.end();
        if(b1 && b2) {
            m[arr[i]] = 1;
        }
        else if(!b1 && !b2) {
            int len1 = m[arr[i]-1];
            int len2 = m[arr[i]+1];
            m[arr[i]] = len1 + 1 + len2;
            m[arr[i]-len1] = m[arr[i]];
            m[arr[i]+len2] = m[arr[i]];
        }
        else if(b1 && !b2) {
            m[arr[i]] = m[arr[i]+1]+1;
            m[arr[i] + m[arr[i]+1] ] = m[arr[i]];
        }
        else {
            m[arr[i]] = m[arr[i]-1]+1;
            m[arr[i] - m[arr[i]-1] ] = m[arr[i]];
        }
    }
    int len = 0;
    for(auto p : m) {
        len = max(len,p.second);
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
    cout<<lenLongestConsecutiveSubseq(arr,n);
    delete [] arr;
    return 0;
}
