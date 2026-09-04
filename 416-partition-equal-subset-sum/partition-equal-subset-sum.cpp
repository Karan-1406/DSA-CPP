class Solution {
public:
    // bool solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
    //     if(target==0)return true;
    //     if(i==0)return nums[0]==target;
    //     if(dp[i][target]!=-1)return dp[i][target];
    //     bool no=solve(i-1,target,nums,dp);
    //     bool take=false;
    //     if(nums[i]<=target) take=solve(i-1,target-nums[i],nums,dp);
    //     return dp[i][target]=no||take;
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)sum+=nums[i];
        //vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
       // vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
        if(sum%2!=0)return false;
        //return solve(n-1,sum/2,nums,dp);
        //for(int i=0;i<n;i++)dp[i][0]=true;
        vector<bool>prev(sum/2 +1,false);
        //if(nums[0]<=sum/2)dp[0][nums[0]]=true;
        prev[0]=true;
        if(nums[0]<=sum/2)prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            vector<bool>cur(sum/2 +1,0);
            for(int j=1;j<=sum/2;j++){
                bool no=prev[j];
                bool take=false;
                if(nums[i]<=j)take=prev[j-nums[i]];
                cur[j]=no||take;
            }
            prev=cur;
        }
        return prev[sum/2];
    }
};