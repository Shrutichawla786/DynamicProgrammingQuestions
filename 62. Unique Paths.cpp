Q.62. Unique Paths
link-->https://leetcode.com/problems/unique-paths/description/
code-->int solve(int  i , int j , vector<vector<long long>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up =solve(i-1 , j , dp);
        int le= solve(i , j-1 , dp);
        return dp[i][j]=(up+le);
    }
    int uniquePaths(int m, int n) {
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        return solve(m-1 , n-1 , dp);
    }
