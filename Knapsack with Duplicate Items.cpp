Q.Knapsack with Duplicate Items
link-->https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code->int solve(int i  , int W , int * wt , int *val , vector<vector<int>>&dp){

        if(i==0){
            return (int(W/wt[0])*val[0]);
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int nottake= solve(i-1 , W , wt , val  , dp);
        int take= INT_MIN;
        if(wt[i]<=W){
            
            take= val[i]+solve(i , W-wt[i] ,wt,val , dp);
        }
        return dp[i][W]=max(take , nottake);
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n ,vector<int>(W+1, -1));
        return solve(n-1 , W , wt , val , dp);
        
    }

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

