Q.Max Sum without Adjacents
link-->https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
code-->	int f(int i , int *arr , vector<int>&dp){
	    if(i==0){
	        return arr[i];
	    }
	    if(i<0){
	        return 0;
	    }
	    if(dp[i]!=-1){
	        return dp[i];
	    }
	    int pick= arr[i]+f(i-2 , arr , dp);
	    int notpick= 0+f(i-1 , arr , dp);
	    return dp[i]= max(pick , notpick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n , -1);
	    return f(n-1 , arr , dp);
	    
	}
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
