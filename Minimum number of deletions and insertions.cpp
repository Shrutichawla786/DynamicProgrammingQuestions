Q.Minimum number of deletions and insertions.
link-->https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code-->int solve(int i1, int i2 ,string &s1, string &s2 , vector<vector<int>>&dp){
        if(i1<0 || i2<0){
            return 0;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(s1[i1]==s2[i2]){
            return 1+solve(i1-1 , i2-1 , s1 , s2 , dp);
        }
        else{
            return dp[i1][i2]= max(solve(i1-1 , i2 , s1 ,s2 , dp) , solve(i1,i2-1 , s1 , s2 , dp));
        }
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        int n1= text1.size();
        int n2= text2.size();
        vector<vector<int>>dp(n1 , vector<int>(n2+1 ,-1));
        return solve(n1-1, n2-1 , text1 , text2 , dp);
    }
	int minOperations(string A, string B) 
	{ 
	    // Your code goes here
	    int n = A.length();
        int m = B.length();
        
        return n+m - 2* longestCommonSubsequence(A , B);	    
	} 
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)
