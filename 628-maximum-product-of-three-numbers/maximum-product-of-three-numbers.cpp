class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // int pos=0,neg=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]>0)pos++;
        //     else if(nums[i]<0)neg++;
        // }
        // int maxi1=max(nums[0]*nums[1],nums[n-1]*nums[n-2]);
        // int maxi2=0;
        // if(maxi1==nums[n-1]*nums[n-2])maxi2=max(nums[0],nums[n-3]);
        // else maxi2=max(nums[2],nums[n-1]);
        
        // if(neg>0)return maxi1*maxi2;
        // else return nums[n-1]*nums[n-2]*nums[n-3];
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};