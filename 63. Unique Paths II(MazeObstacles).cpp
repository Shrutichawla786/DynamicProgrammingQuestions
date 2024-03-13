Q.63. Unique Paths II
link-->https://leetcode.com/problems/unique-paths-ii/
code-->class Solution {
public:
    int solve(int i , int j , vector<vector<int>>&dp ,vector<vector<int>>&a){
        if(i>=0 && j>=0 && a[i][j]==1 ){
            return 0;
        }
        if(i==0&&j==0){
            return 1;
        }
        if(i<0 ||j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up= solve(i-1 , j , dp , a);
        int le= solve(i , j-1 , dp , a);
        return dp[i][j]= up+le;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n ,vector<int> (m,-1));
        return solve( n-1 , m-1 , dp ,obstacleGrid );
    }
};

T.C-->O(N)
S.C-->O(N)
