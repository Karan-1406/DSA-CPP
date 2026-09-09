class Solution {
public:
    // int solve(int i,int ans,vector<int>&coins,vector<vector<int>>&dp){
    //     if(i==0){
    //        if(ans%coins[i]==0)return dp[i][ans]=ans/coins[i];
    //        return 1e9;
    //     }
    //     if(dp[i][ans]!=-1)return dp[i][ans];
    //     int notpick=solve(i-1,ans,coins,dp);
    //     int pick=1e9;
        
    //     if(coins[i]<=ans) pick= 1+solve(i,ans-coins[i],coins,dp);
    //     return dp[i][ans]=min(pick,notpick);
        
    // }
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(),coins.end());
        int n=coins.size();
        //vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        //int ans= solve(n-1,amount,coins,dp);
        for(int j=0; j<=amount; j++){
    if(j % coins[0] == 0)
        dp[0][j] = j / coins[0];
    else
        dp[0][j] = 1e9;
}
        //return ans==1e9?-1:ans;
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notpick=dp[i-1][j];
                int pick=1e9;
                if(coins[i]<=j)pick=1+dp[i][j-coins[i]];
                dp[i][j]=min(pick,notpick);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};