class Solution {
public:
    // int fun(int i,int j,vector<vector<int>>&dp){
    //     if(i==0 && j==0)return 1;
    //     if(i<0 || j<0)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=fun(i-1,j,dp)+fun(i,j-1,dp);
    // }
    int uniquePaths(int m, int n) {
         vector<vector<int>>dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,dp);

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)dp[i][j]=1;
        //         else{
        //             int up=0,down=0;
        //             if(i>0)up=dp[i-1][j];
        //             if(j>0)down=dp[i][j-1];
        //             dp[i][j]=up+down;
        //         }
        //     }
        // }
        for(int i=0;i<m;i++){
            
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0)continue;
                else{
                    int up=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};