class Solution {
public:
    // int solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp,int offset){
    //     if(i==0){
    //         if(target==0 && nums[0]==0)return 2;
    //         if(target==nums[0]||target==-nums[0])return 1;
    //         return 0;
    //     }
    //     if(target>offset || target<-offset)return 0;
    //     if(dp[i][target+offset]!=-1)return dp[i][target+offset];
    //     //if(target==0)return 1;
    //     int plus=solve(i-1,target-nums[i],nums,dp,offset);
    //     int minus=solve(i-1,target+nums[i],nums,dp,offset);
    //     return dp[i][target+offset]=plus+minus;
    // }
    int solve(int i,int ans,vector<int>&nums,vector<vector<int>>&dp){
        if(i==0){
            if(ans==0 && nums[0]==0)return 2;
            if(nums[i]==ans || ans==0)return 1;
            return 0;
        }
        if(dp[i][ans]!=-1)return dp[i][ans];
        int notpick=solve(i-1,ans,nums,dp);
        int pick=0;
        if(nums[i]<=ans)pick=solve(i-1,ans-nums[i],nums,dp);
        return dp[i][ans]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)sum+=it;
        //vector<vector<int>>dp(n+1,vector<int>(2*sum +1,-1));
        if(abs(target) > sum) return 0;
        if((target+sum)%2!=0 )return 0;
        int ans=(target+sum)/2;
        vector<vector<int>>dp(n+1,vector<int>(ans+1,-1));
        return solve(n-1,ans,nums,dp);
    }
};