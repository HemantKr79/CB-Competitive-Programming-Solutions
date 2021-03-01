#include <iostream>
#include <cmath>
using namespace std;

int query(int *blocks,int *arr,int l,int r,int rn) {
    int ans = 0;
    while(l%rn!=0 && l!=0 && l<r) {
        ans += arr[l];
        ++l;
    }
    while(l+rn < r) {
        int block_id = l/rn;
        ans += blocks[block_id];
        l += rn;
    }
    while(l <= r) {
        ans += arr[l];
        ++l;
    }
    return ans;
}

void update(int *blocks,int *arr,int i,int val,int rn) {
    int block_id = i/rn;
    blocks[block_id] += (val - arr[i]);
    arr[i] = val;
}

int main() {
    int arr[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(arr)/sizeof(n);
    int rn = sqrt(n);
    int *blocks = new int[rn+1]{0};
    int block_id = -1;
    for(int i=0;i<n;i++) {
        // new block start if i is multiple of rn
        if(i%rn==0) {
            block_id++;
        }
        blocks[block_id] += arr[i];
    }
    int l,r;
    cin>>l>>r;
    update(blocks,arr,2,15,rn);
    cout<<query(blocks,arr,l,r,rn);
    delete [] blocks;
    return 0;
}