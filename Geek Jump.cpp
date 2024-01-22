linkk->https://www.geeksforgeeks.org/problems/geek-jump/1
Q.Geek Jump
code-->
  int miniEn(int i,vector<int>& height , vector<int>&dp){
      if(i==0){
          return 0;
      }
      if(dp[i]!=-1){
          return dp[i];
      }
      int left = miniEn(i-1 , height , dp)+abs(height[i]-height[i-1]);
      int right= INT_MAX;
      if(i>1){
          right= miniEn(i-2 , height , dp)+abs(height[i]-height[i-2]);
      }
      return dp[i] =min(left , right);
      
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1 ,-1);
        return miniEn( n-1,height  , dp);
         
    }
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)
