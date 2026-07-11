class Solution {
public:
    bool dfs(int start,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj,vector<int>&ans){
        vis[start]=1;
        pathvis[start]=1;
        for(int i:adj[start]){
            if(vis[i]==0){
                if(dfs(i,vis,pathvis,adj,ans))return true;
            }
            else if(pathvis[i])return true;

        }
        pathvis[start]=0;
        ans.push_back(start);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses+1);
        vector<int>ans;
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);

        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};