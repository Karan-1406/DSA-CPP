class Solution {
public:
    // int f(int i, int bought, int cap, vector<int>& prices,
    //       vector<vector<vector<int>>>& dp) {
    //     if (i == prices.size() || cap == 0)
    //         return 0;
    //     if (dp[i][bought][cap] != -1)
    //         return dp[i][bought][cap];

    //     int profit = 0;
    //     if (!bought) {
    //         profit = max(-prices[i] + f(i + 1, 1, cap, prices, dp),
    //                      f(i + 1, 0, cap, prices, dp));
    //     } else {
    //         profit = max(prices[i] + f(i + 1, 0, cap - 1, prices, dp),
    //                      f(i + 1, 1, cap, prices, dp));
    //     }
    //     return dp[i][bought][cap] = profit;
    //}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return f(0, 0, 2, prices,dp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                dp[i][j][0] = 0;
            }
        }
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 2; j++) {
                dp[n][i][j] = 0;
            }
        }
        for (int i = n-1; i>=0; i--) {
            for (int bought = 0; bought <= 1; bought++) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if (!bought) {
                        profit = max(-prices[i] + dp[i + 1][1][cap],dp[i+1][0][cap]);
                                     
                    } else {
                        profit =
                            max(prices[i] + dp[i+1][0][cap-1],dp[i+1][1][cap]);
                                
                    }
                    dp[i][bought][cap]=profit;
                }
            }
        }
        return  dp[0][0][2];
    }
};