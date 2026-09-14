class Solution {
public:
    // int f(int i,int bought,int fee,vector<int>&prices,vector<vector<int>>&dp){
    //     if(i==prices.size()+1)return 0;
    //     if(dp[i-1][bought]!=-1)return dp[i-1][bought];
    //     int profit=0;
    //     if(!bought){
    //         profit=max(-prices[i-1]-fee+f(i+1,1,fee,prices,dp),f(i+1,0,fee,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[i-1]+f(i+1,0,fee,prices,dp),f(i+1,1,fee,prices,dp));
    //     }
    //     return dp[i-1][bought]=profit;
    // }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(3,-1));
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        for(int i=0;i<2;i++){
            dp[n][i]=0;
            //dp[n+1][i]=0;
        }
        //return f(1,0,fee,prices,dp);
        for(int i=n-1;i>=0;i--){
            for(int bought=0;bought<2;bought++){
                int profit=0;
                if(!bought){
                    profit=max(-prices[i]-fee+dp[i+1][1],dp[i+1][0]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                dp[i][bought]=profit;
            }
        }
        return dp[0][0];
    }
};