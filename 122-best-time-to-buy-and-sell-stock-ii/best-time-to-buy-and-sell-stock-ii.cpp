class Solution {
public:
    int f(int i, int bought, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][bought] != -1)
            return dp[i][bought];
        int profit = 0;
        if (!bought) {
            profit = max(-prices[i] + f(i + 1, 1, prices, dp),
                         f(i + 1, 0, prices, dp));
        } else {
            profit = max(prices[i] + f(i + 1, 0, prices, dp),
                         f(i + 1, 1, prices, dp));
        }
        return dp[i][bought] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // return f(0,0,prices,dp);
        dp[n][1] = 0;
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int bought = 0; bought <= 1; bought++) {
                int profit = 0;
                if (!bought) {
                    profit = max(-prices[i] + dp[i+1][1],
                                 dp[i+1][0]);
                } else {
                    profit = max(prices[i] + dp[i+1][0],
                                 dp[i+1][1]);
                }
                dp[i][bought]=profit;
            }
        }
        return dp[0][0];
    }
};