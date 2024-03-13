Q.931. Minimum Falling Path Sum
link-->https://leetcode.com/problems/minimum-falling-path-sum/description/
code-->class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j<0 or j>=n)
            return 1e9;
        if(i==0)
            return matrix[0][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=matrix[i][j]+solve(i-1,j,n,matrix,dp);
        int leftdiagnol=matrix[i][j]+solve(i-1,j-1,n,matrix,dp);
        int rightdiagnol=matrix[i][j]+solve(i-1,j+1,n,matrix,dp);
        
    return dp[i][j]=min(up,min(leftdiagnol,rightdiagnol));        
    }
        
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int mini=1e8;
        for(int j=0;j<n;j++)
        {
            mini=min(mini, solve(n-1, j, n, matrix, dp));
        }
    return mini;
    }
};
  T.c-->O(N*M)
  S.C-->O(N);
