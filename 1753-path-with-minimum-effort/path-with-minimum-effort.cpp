class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
            vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
            pq.push({0,{0,0}});
            effort[0][0]=0;
            int mini=INT_MAX;
            while(!pq.empty()){
                int cureffort=pq.top().first;
                int row=pq.top().second.first;
                int col=pq.top().second.second;
                pq.pop();
                if(cureffort>effort[row][col])continue;
                if(row==n-1 && col==m-1)return cureffort;
                int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++){
                    int r=row+drow[i];
                    int c=col+dcol[i];
                    
                    if(r<n && r>=0 && c<m && c>=0 ){
                        int dif=abs(heights[row][col]-heights[r][c]);
                        int maxi=max(cureffort,dif);
                        if(maxi<effort[r][c]){
                            effort[r][c]=maxi;
                            pq.push({maxi,{r,c}});
                        }
                    }
                }
            }
            return 0;

    }
};