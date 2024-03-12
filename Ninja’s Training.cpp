Q. Ninja’s Training
link->https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM&customSource=studio_nav&count=25&page=1&search=&sort_entity=order&sort_order=ASC
code-->int solve(int days ,int last, vector<vector<int>>& points , vector<vector<int>>&dp){
    if(days==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi , points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[days][last]!=-1){
        return dp[days][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        
        if(task!=last){
            int point= points[days][task]+solve(days-1 , task , points , dp);
            maxi=max(maxi , point);
        }
    }
    return dp[days][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n ,vector<int>(4,-1));
    return solve(n-1 , 3 , points , dp);

}
