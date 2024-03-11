Q.509. Fibonacci Number
link-->https://leetcode.com/problems/fibonacci-number/description/


//memoization
  
code-->int fibo(int n ,vector<int>&dp ){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       return dp[n]= fibo(n-1 , dp )+fibo(n-2 , dp);

    }
    int fib(int n) {
        vector<int>dp(n+1 , -1);
        int ans= fibo(n , dp);
        return ans;
    }
T.c=O(n)
S.c=O(n)


Tabulasation
 int fib(int n) {
        if(n==1 ||n==0){
            return n;
        }
        int prev2=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curri= prev1+prev2;
            prev2=prev1;
            prev1=curri;
        }
return prev1;
    }
T.c=O(n)
S.c=O(n)
