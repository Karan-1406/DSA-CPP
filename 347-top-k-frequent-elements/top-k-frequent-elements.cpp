class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int , int> mp ;
      for(auto ele : nums){
        mp[ele]++ ;
      }
      vector<pair<int , int>> vec ;
      for(auto ele : mp){
        vec.push_back({ele.second , ele.first}) ;
      }
      sort(vec.rbegin() , vec.rend()) ;
      vector<int> ans ;
      for(int i=0 ;i<k ;i++){
        ans.push_back(vec[i].second) ;
      }
      return ans ;
    }
};