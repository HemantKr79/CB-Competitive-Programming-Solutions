#include <iostream>
#include <unordered_set>
using namespace std;

int lenLongestConsecutiveSubseq(int *arr,int n) {
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        s.insert(arr[i]);
    }
    int len = 0;
    for(int i=0;i<n;i++) {
        if(s.find(arr[i]-1)==s.end()) {
            int streak_cnt = 0;
            int curr = arr[i];
            while(s.find(curr)!=s.end()) {
                streak_cnt++;
                curr++;
            }
            len = max(len,streak_cnt);
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
    cout<<lenLongestConsecutiveSubseq(arr,n);
    delete [] arr;
    return 0;
}
