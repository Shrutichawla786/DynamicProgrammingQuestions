Q.1312. Minimum Insertion Steps to Make a String Palindrome
link-->https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
code-->class Solution {
public:
int solve(int i1, int i2 ,string &s1, string &s2 , vector<vector<int>>&dp){
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
    int longestPalindromeSubseq(string s) {
        string t= s;
        reverse(t.begin() , t.end());
        int n = s.length();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return solve(n-1 , n-1 ,s , t , dp);
    }
    int minInsertions(string s) {
        return s.length()-   longestPalindromeSubseq(s);
    }
};
