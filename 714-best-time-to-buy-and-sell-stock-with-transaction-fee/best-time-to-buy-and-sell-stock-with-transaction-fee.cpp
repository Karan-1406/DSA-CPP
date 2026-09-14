class Solution {
public:
    int f(int i,int bought,int fee,vector<int>&prices,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][bought]!=-1)return dp[i][bought];
        int profit=0;
        if(!bought){
            profit=max(-prices[i]-fee+f(i+1,1,fee,prices,dp),f(i+1,0,fee,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,0,fee,prices,dp),f(i+1,1,fee,prices,dp));
        }
        return dp[i][bought]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,fee,prices,dp);
    }
};