class Solution {
public:
    int maxi=0;
    int solve(int i,int j,vector<vector<char>>&matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
       
        if( i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //if(i==n-1 && j==m-1)return 1;
        // if(matrix[i][j]=='0')return 0;
        //int right=0,down=0,diag=0;
        int right=solve(i,j+1,matrix,dp);
        int down=solve(i+1,j,matrix,dp);
        int diag=solve(i+1,j+1,matrix,dp);
        if(matrix[i][j]=='1'){
            int ans=1+min(right,min(down,diag));
            maxi=max(maxi,ans);
            return dp[i][j]=ans;
        }
        return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       vector<vector<int>>dp(m,vector<int>(n,-1));
       solve(0,0,matrix,dp); 
       return maxi*maxi;
    
    }
};