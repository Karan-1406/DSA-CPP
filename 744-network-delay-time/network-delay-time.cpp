class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int a=times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<a;i++){
            int src=times[i][0];
            int dst=times[i][1];
            int dist=times[i][2];
            adj[src].push_back({dst,dist});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >q;
        vector<int>arr(n+1,INT_MAX);
        q.push({0,k});
        arr[k]=0;
        while(!q.empty()){
            int distance=q.top().first;
            int node=q.top().second;
            q.pop();
            if (distance > arr[node]) continue;
            for(auto it:adj[node]){
                int curnode=it.first;
                int curdist=it.second;
                if(curdist+distance<arr[curnode]){
                    q.push({curdist+distance,curnode});
                    arr[curnode]=curdist+distance;
                }
            }
        }
        int x=arr.size();
        //sort(arr.begin(),arr.end());
        int ans=INT_MIN;
        for(int i=1;i<x;i++){
            if(arr[i]==INT_MAX)return -1;
            ans=max(ans,arr[i]);
        }
        return ans;
        
    }
};