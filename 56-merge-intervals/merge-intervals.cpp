class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int front=intervals[0][0];
        int back=intervals[0][1];

        vector<vector<int>>temp;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=back){
                back=max(back,intervals[i][1]);
            }
            else{
                temp.push_back({front,back});
                front=intervals[i][0];
                back=intervals[i][1];
            }
        }
        temp.push_back({front,back});
        return temp;
    }
};