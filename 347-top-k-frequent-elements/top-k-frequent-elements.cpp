class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>mpp;
      for(int i:nums){
        mpp[i]++;
      }
      vector<vector<int>>ans;
      for(auto it:mpp){
        ans.push_back({it.second,it.first});
        
      }
      sort(ans.rbegin(),ans.rend());
      vector<int>fans;
      for(int i=0;i<k;i++){
        fans.push_back(ans[i][1]);
      }
      return fans;
    }
};