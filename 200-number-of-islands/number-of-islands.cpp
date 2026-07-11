class Solution {
public:
    void bfs(vector<vector<int>>&vis,int row,int col,vector<vector<char>>&grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int rowf=r+drow[i];
                int colf=c+dcol[i];
                if(rowf>=0 && rowf<grid.size() && colf>=0 && colf<grid[0].size() && !vis[rowf][colf] && grid[rowf][colf]=='1'){
                    q.push({rowf,colf});
                    vis[rowf][colf]=1;
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        //queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    //q.push({i,j});
                    ans++;
                    bfs(vis,i,j,grid);
                }
            }
        }
        return ans;
    }
};