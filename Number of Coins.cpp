Q.Number of Coins
link-->https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code->int solve(int i , int target ,vector<int>& coins , vector<vector<int>>&dp ){
        if(target==0){
            return 0;
        }
        if(target<0){
            return INT_MAX;
        }
        if(i==0){
            if(target%coins[i]==0){
                return target/coins[0];
            }
            return 1e9;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        int  nottake= solve(i-1 , target , coins , dp);
        int take=1e9;
        if(target>= coins[i]){
            take = 1+solve(i , target-coins[i] , coins , dp);
        }
        return dp[i][target]= min(take , nottake);
    }
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M , vector<int>(V+1 , -1));
	    int ans= solve(M-1 , V , coins , dp);
	    if(ans == INT_MAX || ans==1e9){
            return -1;
        }
        return ans;
         
	} 

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)
