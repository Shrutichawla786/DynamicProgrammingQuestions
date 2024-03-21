Q.121. Best Time to Buy and Sell Stock
link-->https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
code->class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit=0;
        int n = prices.size();
        for(int i=1;i<n;i++){
           int cost= prices[i]-mini;
            profit= max(cost , profit);
            mini = min(mini , prices[i]);

        }
        return profit;
    }
};
