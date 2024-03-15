Q.Minimum sum partition
link-->https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code--> int solve(int i , int k , int *arr , vector<vector<int>>&dp){
        
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum=0;
	    for(int i=0;i<n;i++){
	        totalSum+=arr[i];
	    }
	    int k = totalSum;
	    
	    vector<vector<bool>>dp(n , vector<bool>(k+1 , 0));
	    for(int i=0;i<n;i++){
	        dp[i][0]=true;
	    }
	    if(arr[0]<=k){
	        dp[0][arr[0]]=true;
	    }
	    for(int i=1;i<n;i++){
	        for(int target=1;target<=k;target++){
	            bool nottake= dp[i-1][target];
	            bool take= false;
	            if(arr[i]<=target){
	                 take= dp[i-1][target-arr[i]];
	                
	            }
	            dp[i][target]=take|nottake;
	            
	        }
	    }
	    int mini=1e9;
	    for(int s1=0;s1<=totalSum/2;s1++){
	        if(dp[n-1][s1]==true){
	            mini= min(mini ,abs((totalSum-s1)-s1));
	        }
	    }
	    return mini;

  }
Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)
