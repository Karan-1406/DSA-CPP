class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //sort(dominoes.begin(),dominoes.end());
        int ans=0;
        unordered_map<int,int>freq;
        for(auto d:dominoes){
            int a=min(d[0],d[1]);
            int b=max(d[0],d[1]);
            int key=a*10+b;
            ans+=freq[key];
            freq[key]++;
        }
        return ans;
    }
};