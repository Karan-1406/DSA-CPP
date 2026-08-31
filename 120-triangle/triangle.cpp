class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    //     int n=triangle.size();
    //     if(i==n-1){
    //         return dp[i][j]=triangle[i][j];
    //     }
    //     if(dp[i][j]!=INT_MAX)return dp[i][j];
    //     int down=solve(i+1,j,triangle,dp);
    //     int diag=solve(i+1,j+1,triangle,dp);
    //     return dp[i][j]=triangle[i][j]+min(down,diag);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        //return solve(0,0,triangle,dp);
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
           // dp[n-1][i]=triangle[n-1][i];
           temp[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>cur(i+1,0);
            for(int j=0;j<=i;j++){
                // if(i==0 && j==0)dp[0][0]=triangle[0][0];
                int down=temp[j];
                int diag=temp[j+1];
                cur[j]=triangle[i][j]+min(down,diag);
            }
            temp=cur;
        }
        return temp[0];
    }
};