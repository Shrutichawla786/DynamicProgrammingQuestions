Q.Coin Change
link-->long long int solve(int i , int* coins , int k , vector<vector<long long int >>&dp){

        if(i==0){
            return (k%coins[0]==0);
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        long long int nottake= solve(i-1 , coins, k , dp);
        long long int take=0;
        if(coins[i]<=k){
            take= solve(i , coins , k-coins[i] , dp);
        }
        
        return dp[i][k]= take+nottake;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N , vector<long long int >(sum+1 , -1));
        return solve(N-1 , coins , sum ,dp);
    }
Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum)
