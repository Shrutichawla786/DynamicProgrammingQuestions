Q.Palindromic Partitioning
code->bool ispalindrome(int i , int j ,string s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int solve(int i , int n , string s , vector<int>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int mincost=INT_MAX;
    for(int j=i;j<n;j++){

        if(ispalindrome(i , j ,s)){
            int cost= 1+solve(j+1 , n , s ,dp);
            mincost= min(mincost , cost);
        }
    }
    return dp[i]= mincost;
}
    int palindromicPartition(string str)
    {
        // code here
         int n = str.size();
        vector<int>dp(n , -1);
        return solve(0 , n , str ,dp)-1;
    }
