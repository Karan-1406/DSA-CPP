class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
       
        // for(int i=0;i<n;i++){
        //      int leftmax=0,rightmax=0;
        //     for(int j=0;j<=i;j++)leftmax=max(leftmax,height[j]);
        //     for(int k=i;k<n;k++)rightmax=max(rightmax,height[k]);
        //     ans+=min(leftmax,rightmax)-height[i];
        // }
        vector<int>left=height,right=height;
        for(int i=1;i<n;i++){
           left[i]=max(left[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i],right[i+1]);
        }
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};