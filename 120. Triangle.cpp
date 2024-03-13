Q.120. Triangle
link-->https://leetcode.com/problems/triangle/description/
code-->class Solution {
public:
    int solve(int i , int j ,int n ,vector<vector<int>>& t,vector<vector<int>>& dp){
        if(i==n-1){
            return t[n-1][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int dow= t[i][j]+solve(i+1 , j ,n ,  t , dp);
        int dia= t[i][j]+solve(i+1 , j+1 ,n ,t , dp);

        return dp[i][j]= min(dow ,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp(n , vector<int>(n,-1));
        return solve( 0 , 0 , n, triangle, dp);

    }
};

T.C-->O(N)
S.C-->O(N)
