class Solution {
public:
    // int solve(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind==0)return nums[ind];
    //     if(ind==-1)return 0;
    //     if(dp[ind]!=-1)return dp[ind];
    //     int pick=nums[ind]+solve(ind-2,nums,dp);
    //     int notpick=solve(ind-1,nums,dp);
    //     return dp[ind]=max(pick,notpick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int>dp(n,-1);
       // return solve(n-1,nums,dp);
       //dp[0]=nums[0];
    //    int neg=0;
    //    for(int i=1;i<n;i++){
    //     int pick=nums[i];
    //     if(i>1) pick=nums[i]+dp[i-2];
    //     int notpick=dp[i-1];
    //     dp[i]=max(pick,notpick);
    //    }
    //    return dp[n-1];
    int prev=nums[0],prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i]+prev2;
        int notpick=prev;
        prev2=prev;
        prev=max(pick,notpick);
    }
    return prev;
    }
};