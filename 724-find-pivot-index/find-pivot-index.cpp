class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return -1;
        int sum1=nums[0],sum2=0;
        
        for(int i=n-1;i>0;i--)sum2+=nums[i];
        if(sum2==0)return 0;
        int i=0,j=1;
        while(j<n){
            
                sum2-=nums[j];
                if(sum1==sum2)return j;
                sum1+=nums[j];
                i++;
                j++;
            
        }
        return -1;
    }
};