class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int i=1;
        int maxi=-1;
        int ans=0;
        for(int i:piles)maxi=max(maxi,i);
        int j=maxi;
        while(i<=j){
            int mid=i+(j-i)/2;
            long long a=0;
            for(auto it:piles){
               a+=(it+mid-1LL)/mid;
            }
            if(a<=h){
                j=mid-1;
                ans=mid;
            }
            else i=mid+1;
        }
        return ans;
    }
};