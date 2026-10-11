class Solution {
public:
    long long dist(vector<int>a){
        return 1LL*a[0]*a[0] + 1LL*a[1]*a[1];
        
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>>ans;
        priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
        for(int i=0;i<n;i++){
            int distance=dist(points[i]);
            pq.push({distance,i});
        }
        while(!pq.empty() && k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};