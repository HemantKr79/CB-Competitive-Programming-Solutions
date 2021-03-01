#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size()+1,1e9);
    dp[0] = -1e9;
    for(int i=0;i<nums.size();i++) {
        for(int j=0;j<dp.size();j++) {
            if(dp[j]<nums[i] && nums[i]<dp[j+1]) {
                dp[j+1] = nums[i];
                break;
            }
        }
    }
    for(int i=dp.size()-1;i>=1;i--) {
        if(dp[i]!=1e9) {
            return i;
        }
    }
    return 0;
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
