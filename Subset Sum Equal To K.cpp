Q. Subset Sum Equal To K
link-->https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&leftPanelTabValue=PROBLEM
code->#include <bits/stdc++.h> 
bool solve(int i , int k , vector<int>&arr , vector<vector<int>>&dp){
    if(k==0){
        return true;
    }
    if(i==0){
        return ( k==arr[i]);
    }

    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    bool nottake= solve(i-1 , k,arr, dp);
    bool take = false;
    if(arr[i]<=k){
        take= solve(i-1 , k-arr[i] , arr , dp);
    }
   
    return dp[i][k]= take |nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n , vector<int>(k+1 , -1));

    return solve(n-1 , k , arr ,dp);
}
