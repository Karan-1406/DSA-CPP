class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //int n=edges.size();
        if(n==1)return {0};
        vector<int>degree(n);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(degree[i]==1)q.push(i);
        }
        int rem=n;
        while(rem>2){
            int sz=q.size();
            rem-=sz;
            while(sz--){
                int node=q.front();
                q.pop();
                for(int i:adj[node]){
                    degree[i]--;
                    if(degree[i]==1)q.push(i);
                }

            }
        }
       vector<int>ans;
       while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
       }
       return ans;

    }
};