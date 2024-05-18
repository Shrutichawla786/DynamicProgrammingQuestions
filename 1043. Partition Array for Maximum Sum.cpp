Q.1043. Partition Array for Maximum Sum
code->class Solution {
public:
    int solve(int i , int n , int k ,vector<int>&arr , vector<int>&dp){
        if(i==n){
            return 0;
        }
        int maxAns=INT_MIN;
        int maxi= INT_MIN;
        int len=0;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j= i ;j< min(n , i+k);j++){
            len++;
            maxi= max(maxi , arr[j]);
            int sum = len*maxi + solve(j+1 , n , k , arr ,dp);
            maxAns= max(maxAns , sum);
        }
        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n , -1);
        return solve(0 , n , k , arr ,dp);
    }
};
