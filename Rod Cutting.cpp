Q.Rod Cutting
link-->https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code--> int solve(int i , int N , int * price , vector<vector<int>>&dp){
        if(i==0){
            return N* price[0];
        }
        if(dp[i][N]!=-1){
            return dp[i][N];
        }
        int nottake= solve(i-1 , N , price , dp);
        int take=INT_MIN;
        int rodlength= i+1;
        if(rodlength<=N){
            take= price[i]+ solve(i , N-rodlength , price , dp);
        }
        return dp[i ][N]=max(take , nottake);
       
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return solve(n-1 , n ,price , dp);
    }

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
