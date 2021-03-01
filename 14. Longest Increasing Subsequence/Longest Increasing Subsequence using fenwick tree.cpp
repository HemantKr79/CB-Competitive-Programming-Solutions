#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fenwick {
    vector<int> f;
    int n;
    void init(int n) {
        this->n = n+2;
        f.resize(this->n,0);
    }
    void update(int x,int val) {
        ++x; // to convert to 1 based indexing
        while(x<n) {
            f[x] = max(f[x],val);
            x += (x & -x);
        }
    }
    int query(int x) {
        ++x; // to convert to 1 based indexing
        int res = 0;
        while(x>0) {
            res = max(res,f[x]);
            x -= (x & -x);
        }
        return res;
    }
};

int lengthOfLIS(vector<int>& nums) {
    fenwick tree;
    tree.init(nums.size());
    vector<pair<int,int> > v(nums.size());
    for(int i=0;i<nums.size();i++) {
        v[i].first = nums[i];
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<int> dp(nums.size(),0);
    for(int i=0;i<v.size();i++) {
        int index = v[i].second;
        int value = v[i].first;
        dp[index] = tree.query(index-1) + 1;
        tree.update(index,dp[index]);
    }
    return *max_element(dp.begin(),dp.end());
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<lengthOfLIS(a);
    return 0;
}
