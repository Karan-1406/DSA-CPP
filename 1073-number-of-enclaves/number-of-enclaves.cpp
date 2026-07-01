class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            
            if(grid[i][0]==1 && !vis[i][0]){
                vis[i][0]=1;
                q.push({i,0});
            }
            
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
           if(grid[0][i]==1 && !vis[0][i]){
                vis[0][i]=1;
                q.push({0,i});
            } 
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1){
                    vis[row][col]=1;
                    q.push({row,col});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1)cnt++;
            }
        }
    return cnt;
    }
};