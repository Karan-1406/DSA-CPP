class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        
        int a=flights.size();
        for(int i=0;i<a;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            adj[u].push_back({v,flights[i][2]});
        }
            queue<pair<int,pair<int,int>>>pq;
            vector<int>dist(n,INT_MAX);
            dist[src]=0;
            pq.push({0,{src,0}});
            while(!pq.empty()){
                int stop=pq.front().first;
                int node=pq.front().second.first;
                int curr=pq.front().second.second;
                pq.pop();
                if(stop>k)continue;
                
                for(auto it:adj[node]){
                    int nextnode=it.first;
                    int distance=it.second;
                    if(dist[nextnode]>curr+distance && stop<=k){
                        pq.push({stop+1,{nextnode,curr+distance}});
                        dist[nextnode]=curr+distance;
                    }
                }
            }
            return dist[dst]==INT_MAX?-1:dist[dst];
    }
};