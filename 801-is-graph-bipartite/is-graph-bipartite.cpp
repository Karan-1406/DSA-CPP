class Solution {
public:
    bool dfs(int start,int col,vector<int>&colour,vector<vector<int>>&graph){
        colour[start]=col;
        for(int i:graph[start]){
            if(colour[i]==-1){
                if(dfs(i,!col,colour,graph)==false)return false;;
            }
            else{
                if(colour[i]==col)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,-1);
        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(dfs(i,0,colour,graph)==false)return false;
            }
        }
        return true;
    }
};