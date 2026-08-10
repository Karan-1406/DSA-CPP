class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       int k=roads.size();
       vector<vector<pair<int,int>>>adj(n);
       priority_queue<
             pair<long long,int>,
             vector<pair<long long,int>>,
             greater<pair<long long,int>>
        > pq;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        int mod=1e9+7;
        pq.push({0,0});
        ways[0]=1;
        dist[0]=0;
        while(!pq.empty()){
            long long distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(distance>dist[node])continue;
            for(auto it:adj[node]){
                int nextnode=it.first;
                int d=it.second;
                
                if(distance+d<dist[nextnode]){
                    dist[nextnode]=distance+d;
                    ways[nextnode]=ways[node];
                    pq.push({dist[nextnode],nextnode});
                }
                else if(distance+d==dist[nextnode]){
                    ways[nextnode]=(ways[nextnode]+ways[node])%mod;
                }

            }
        }
        return ways[n-1];
        
    }
};