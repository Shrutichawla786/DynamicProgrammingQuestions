Q.122. Best Time to Buy and Sell Stock II
link-->https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
code-->class Solution {
public:
    int solve(int i , int buy , vector<int>&prices , int n , vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            profit= max(-prices[i]+solve(i+1 , 0 ,prices, n , dp) , 0+ solve(i+1 , 1,prices , n,dp));
        }
        else{
            profit= max(prices[i]+solve(i+1 , 1,prices,n,dp) , 0+solve(i+1 , 0,prices,n,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2,-1));
        return solve(0 , 1 , prices , n , dp);
    }
};
t.c-->
s.c-->
