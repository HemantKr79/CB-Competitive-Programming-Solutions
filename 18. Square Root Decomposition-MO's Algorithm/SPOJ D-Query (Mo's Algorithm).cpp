


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct query {
    int l,r,q_no,block_id;
    bool operator < (query &q) {
        if(block_id==q.block_id) {
            return r < q.r; 
        }
        return block_id < q.block_id;
    }
};

vector<int> freq(1000001,0);
int distinct = 0;

void add(int element) {
    if(freq[element]==0) {
        distinct++;
    }
    freq[element]++;
}

void remove(int element) {
    freq[element]--;
    if(freq[element]==0) {
        distinct--;
    }
}

void resolve(int &curr_l,int &curr_r,int l,int r,vector<int> &arr) {
    while(curr_l < l) {
        remove(arr[curr_l]);
        ++curr_l;
    }
    while(curr_l > l) {
        --curr_l;
        add(arr[curr_l]);
    }
    while(curr_r < r) {
        ++curr_r;
        add(arr[curr_r]);
    }
    while(curr_r > r) {
        remove(arr[curr_r]);
        --curr_r;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int rn = sqrt(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    vector<query> q(t);
    for(int i=0;i<t;i++) {
        cin>>q[i].l;
        cin>>q[i].r;
        q[i].l -= 1;
        q[i].r -= 1;
        q[i].q_no = i; 
        q[i].block_id = q[i].l/rn;
    }
    sort(q.begin(),q.end());
    vector<int> ans(t);
    int curr_l = q[0].l;
    int curr_r = q[0].r;
    for(int i=curr_l;i<=curr_r;i++) {
        add(arr[i]);
    }
    ans[q[0].q_no] = distinct;
    for(int i=1;i<t;i++) {
        resolve(curr_l,curr_r,q[i].l,q[i].r,arr);
        ans[q[i].q_no] = distinct;
    }
    for(int i=0;i<t;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
