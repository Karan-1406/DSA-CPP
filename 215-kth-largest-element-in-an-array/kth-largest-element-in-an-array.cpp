class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)pq.push(nums[i]);
        int a=1;
        while(a!=k){
            pq.pop();
            a++;
            
        }
        
        return pq.top();
    }
};