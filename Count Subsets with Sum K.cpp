Q.Count Subsets with Sum K
link-->https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM
code-->int solve( int i ,vector<int>& arr, int k,vector<vector<int>>&dp){
	if(i==0){
		if(k==0 && arr[0]==0){
			return 2;
		}
		if(k==0 || arr[0]==k){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[i][k]!=-1){
		return dp[i][k];
	}
	int notpi= solve(i-1 , arr , k , dp);
	int pi=0;
	if(arr[i]<=k){
		pi=solve(i-1 , arr , k-arr[i] , dp);
	}
	return dp[i][k]= notpi+pi;
	
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n , vector<int>(k+1 , -1));
	return solve(n-1 , arr , k , dp);
}
