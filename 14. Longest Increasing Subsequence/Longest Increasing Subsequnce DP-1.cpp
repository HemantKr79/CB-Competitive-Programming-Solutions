#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    vector<int> dp(nums.size(),1);
    for(int i=0;i<nums.size();i++) {
        for(int j=0;j<i;j++) {
            if(nums[i]>nums[j]) {
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
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