class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=0;
        vector<int>ans;
        int dir=1;
        for(int k=0;k<n*m;k++){
            ans.push_back(mat[i][j]);
            if(dir==1){//up right
                if(j==m-1){
                    i++;
                    dir=-1;
                }
                else if(i==0){
                    j++;
                    dir=-1;
                }
                else{
                    i--;
                    j++;
                }
            }
            else{
                if(i==n-1){
                    j++;
                    dir=1;
                }
                else if(j==0){
                    i++;
                    dir=1;
                }
                else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};