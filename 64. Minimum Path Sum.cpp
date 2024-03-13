Q.64. Minimum Path Sum
link-->https://leetcode.com/problems/minimum-path-sum/description/
code-->class Solution {
public:
    int solve(int i , int j ,vector<vector<int>>& a , vector<vector<int>>&dp ){
        if(i<0 ||j<0){
            return 1e9;
        }
        if(i==0 && j==0){
            return a[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up= a[i][j]+solve(i-1 , j , a , dp);
        
        int le= a[i][j]+solve(i,j-1,a,dp);
        return dp[i][j]= min(up , le);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m,-1));
        return solve(n-1 , m-1 , grid , dp);
    }
};
T.C-->O(N)
S.C-->O(N)
