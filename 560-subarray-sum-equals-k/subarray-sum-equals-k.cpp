class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
       int ans=0;
       int sum=0;
       unordered_map<int,int>mpp;
       mpp[0]=1;
       for(int i=0;i<n;i++){
        sum+=nums[i];
        int need=sum-k;
        if(mpp.count(need)){
            ans+=mpp[need];
        }
        mpp[sum]++;
       }
       return ans;
    }
};