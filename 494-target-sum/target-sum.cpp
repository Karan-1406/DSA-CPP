class Solution {
public:
    int solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp,int offset){
        if(i==0){
            if(target==0 && nums[0]==0)return 2;
            if(target==nums[0]||target==-nums[0])return 1;
            return 0;
        }
        if(target>offset || target<-offset)return 0;
        if(dp[i][target+offset]!=-1)return dp[i][target+offset];
        //if(target==0)return 1;
        int plus=solve(i-1,target-nums[i],nums,dp,offset);
        int minus=solve(i-1,target+nums[i],nums,dp,offset);
        return dp[i][target+offset]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)sum+=it;
        vector<vector<int>>dp(n+1,vector<int>(2*sum +1,-1));
        return solve(n-1,target,nums,dp,sum);
    }
};