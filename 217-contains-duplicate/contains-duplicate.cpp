class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        // if(n==1)return false;
        // int x=0;
        // vector<int>arr(n);
        // for(int i=0;i<n;i++){
        //     arr[i]=i+1;
        //     x=arr[i]^nums[i];
        // }
        // if(x==0)return false;
        // return true;
        unordered_map<int,int>mpp;
        for(int num:nums){
            mpp[num]++;
        }
        for(auto it:mpp){
            if(it.second>=2)return true;
        }
        return false;

    }
};