Q.300. Longest Increasing Subsequence
link-->https://leetcode.com/problems/longest-increasing-subsequence/description/
code-->class Solution {
public:
    int solve(int i , int pre_i , int n ,vector<int>& nums , vector<vector<int>>&dp ){
        if(i==n){
            return 0;
        }
        if(dp[i][pre_i+1]!=-1){
            return dp[i][pre_i+1];
        }
        int len=0+solve(i+1 , pre_i , n , nums,dp);
        if(pre_i==-1||nums[i]>nums[pre_i]){
            len = max(len , 1+solve(i+1 , i , n,nums ,dp));
        }
        return dp[i][pre_i+1]= len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return solve(0 ,-1,n , nums , dp);
        
    }
};
