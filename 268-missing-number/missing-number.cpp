class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int i=0;
        int j=n-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid==nums[mid]){
                
                i=mid+1;
            }
            else j=mid-1;
        }
        return i;

    }
};