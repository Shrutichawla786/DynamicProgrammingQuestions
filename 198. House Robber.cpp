Q.198. House Robber
link-->https://leetcode.com/problems/house-robber/description/
code-->int f( int i , vector<int>&arr, vector<int>&dp){
    if(i==0){
        return arr[i];
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int pick=arr[i]+f(i-2 , arr , dp);
    int notpick= 0+f(i-1 , arr , dp);
    return dp[i]= max(pick , notpick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , -1);
        return f(n-1 , nums ,dp);
    }
