Q.Longest Common Substring
link-->https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
code-->    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1 , vector<int>(m+1 ,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                    maxi=max(maxi , dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
                
            }
        }
        return maxi;
        
    }
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).
