class Solution {
public:
    // int f(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
    //     if(i==nums.size())return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];

    //     int notpick=f(i+1,prev,nums,dp);
    //     int pick=0;
    //     if(prev==-1 || nums[i]>nums[prev])pick=1+f(i+1,i,nums,dp);
    //     return dp[i][prev+1]=max(pick,notpick);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int notpick=dp[i+1][j+1];
                int pick=0;
                if(j==-1 || nums[i]>nums[j])pick=1+dp[i+1][i+1];
                dp[i][j+1]=max(pick,notpick);
            }
        }
        // return f(0,-1,nums,dp);
        return dp[0][0];
    }
};