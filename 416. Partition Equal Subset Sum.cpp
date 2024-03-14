Q.416. Partition Equal Subset Sum
link-->https://leetcode.com/problems/partition-equal-subset-sum/description/
code--->class Solution {
public:
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
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        int k=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            k= sum/2;
        }
        vector<vector<int>>dp(n , vector<int>(k+1 , -1));
        return solve(n-1 ,k ,nums , dp  );
    }
};
