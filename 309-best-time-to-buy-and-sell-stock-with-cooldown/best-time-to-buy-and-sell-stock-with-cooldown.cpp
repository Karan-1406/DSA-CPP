class Solution {
public:
    int f(int i,int bought,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][bought]!=-1)return dp[i][bought];
        int profit=0;
        if(!bought){
            profit=max(-prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+2,0,prices,dp),f(i+1,1,prices,dp));
        }
        return dp[i][bought]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return f(0,0,prices,dp);
    }
};