Q.123. Best Time to Buy and Sell Stock III
link->https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
code-->class Solution {
public:
int solve(int i , int buy ,int count ,vector<int>&prices , int n , vector<vector<vector<int>>>&dp){
        if(i==n){
            return 0;
        }
        if(count==0){
            return 0;
        }
        if(dp[i][buy][count]!=-1){
            return dp[i][buy][count];
        }
        int profit=0;
        if(buy){
            profit= max(-prices[i]+solve(i+1 , 0 ,count,prices, n , dp) , 0+ solve(i+1 , 1,count,prices , n,dp));
        }
        else{
            profit= max(prices[i]+solve(i+1 , 1,count-1,prices,n,dp) , 0+solve(i+1 , 0,count,prices,n,dp));
        }
        return dp[i][buy][count]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n , 
        vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0 , 1 ,2, prices , n , dp);
    }
};
