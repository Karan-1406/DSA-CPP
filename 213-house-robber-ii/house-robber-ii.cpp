class Solution {
public:
    int solve(int start,int end,vector<int>&nums){
         //int n=nums.size();
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
    int prev=0,prev2=0;
    for(int i=start;i<=end;i++){
        int pick=nums[i]+prev2;
        int notpick=prev;
        prev2=prev;
        prev=max(pick,notpick);
    }
    return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }
};