class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        int ans=0;
        // for(int i=0;i<n-1;i++){
        //     unordered_map<int,int>mpp;
        //     mpp[nums[i]]++;
        //     for(int j=i+1;j<n;j++){
        //     mpp[nums[j]]++;
        //     if(mpp[0]==mpp[1])ans=max(ans,mpp[0]+mpp[1]);
        //     }
        // }
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)sum--;
            else sum++;
            if(mpp.find(sum)!=mpp.end()){
                ans=max(ans,i-mpp[sum]);
            }
            else mpp[sum]=i;
        }
        return ans;

    }
};