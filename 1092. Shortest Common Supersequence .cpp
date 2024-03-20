Q.1092. Shortest Common Supersequence 
link-->https://leetcode.com/problems/shortest-common-supersequence/description/
code-->class Solution {
public:

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1));
    
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n, j = m;
        string ans;
        while(i && j) {
            if(s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--, j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) ans += s1[i - 1], i--;
            else ans += s2[j - 1], j--;
        }
        while(i) ans += s1[--i];
        while(j) ans += s2[--j];

        reverse(ans.begin(), ans.end());
        return ans;
        }
};
