class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)arr.push_back({i,j});
            }
        }
        for(int i=0;i<arr.size();i++){
            int r=arr[i][0];
            int c=arr[i][1];
            for(int i=0;i<m;i++)matrix[r][i]=0;
            for(int i=0;i<n;i++)matrix[i][c]=0;
        }
        
    }
};