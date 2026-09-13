class Solution {
public:
    int f(int i, int bought, int cap, vector<int>& prices,vector<vector<vector<int>>>&dp) {
        if (i == prices.size() || cap == 0)
            return 0;
        if(dp[i][bought][cap]!=-1)return dp[i][bought][cap];

        int profit = 0;
        if (!bought) {
            profit = max(-prices[i] + f(i + 1, 1, cap, prices,dp),
                         f(i + 1, 0, cap, prices,dp));
        } else {
            profit = max(prices[i] + f(i + 1, 0, cap - 1, prices,dp),
                         f(i + 1, 1, cap, prices,dp));
        }
        return dp[i][bought][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 2, prices,dp);
    }
};