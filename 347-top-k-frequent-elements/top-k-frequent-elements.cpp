class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    //   unordered_map<int,int>mpp;
    //   for(int i:nums){
    //     mpp[i]++;
    //   }
    //   vector<vector<int>>ans;
    //   for(auto it:mpp){
    //     ans.push_back({it.second,it.first});
        
    //   }
    //   sort(ans.rbegin(),ans.rend());
    //   vector<int>fans;
    //   for(int i=0;i<k;i++){
    //     fans.push_back(ans[i][1]);
    //   }
    //   return fans;
    // int n=nums.size();
    // sort(nums.begin(),nums.end());
    // priority_queue<pair<int,int>>pq;
    // int cnt=1;
    // for(int i=1;i<n;i++){
    //     if(nums[i]!=nums[i-1]){
    //         pq.push({cnt,nums[i-1]});
    //         cnt=1;
    //     }
    //     else cnt++;
    // }
    // pq.push({cnt, nums[n-1]});
    // vector<int>ans;
    // while(k--){
    //     ans.push_back(pq.top().second);
    //     pq.pop();
    // }
    // return ans;
    int n=nums.size();
     priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
    unordered_map<int,int>mpp;
    for(auto it:nums)mpp[it]++;
    //int cnt=1;
    for(auto it:mpp){
        pq.push({it.second,it.first});
        
    if(pq.size()>k)pq.pop();
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};