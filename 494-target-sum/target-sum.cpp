class Solution {
public:
    int solve(int i,int target,vector<int>&nums){
        if(i==0){
            if(target==0 && nums[0]==0)return 2;
            if(target==nums[0]||target==-nums[0])return 1;
            return 0;
        }
        //if(target==0)return 1;
        int plus=solve(i-1,target-nums[i],nums);
        int minus=solve(i-1,target+nums[i],nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,target,nums);
    }
};