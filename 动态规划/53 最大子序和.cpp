class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()+1]={0};
        
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        }
        
        return *max_element(dp,dp+nums.size());
    }
};

//12 ms	9.1 MB
