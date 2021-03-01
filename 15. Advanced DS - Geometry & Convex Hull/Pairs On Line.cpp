#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n,m,c;
    cin>>n>>m>>c;
    int *arr = new int[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int cnt = 0;
    for(int i=0;i<n;i++) {
        int y = m*arr[i] + c;
        int index = lower_bound(arr,arr+n,y) - arr;
        while(index<n) {
            if(index==i) {
                ++index;
                continue;
            }
            if(arr[index]!=y) {
                break;
            }
            ++cnt;
            ++index;
        }
    }
    cout<<cnt;
}