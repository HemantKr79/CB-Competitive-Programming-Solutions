#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size()+1,1e9);
    dp[0] = -1e9;
    for(int i=0;i<nums.size();i++) {
        int pos = upper_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
        if(dp[pos-1]<nums[i] && nums[i]<dp[pos]) {
            dp[pos] = nums[i];
        }
    }
    int len = 0;
    for(int i=1;i<dp.size();i++) {
        if(dp[i]!=1e9) {
            len = i;
        }
    }
    return len;
}

int main() {
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++) {
        cin>>input[i];
    }
    cout<<lengthOfLIS(input);
    return 0;
}
