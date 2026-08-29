class Solution {
public:
    // int solve(int i,int j,string word1,string word2,vector<vector<int>>&dp){
    //     if(i<0)return j+1;
    //     if(j<0)return i+1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(word1[i]==word2[j]){
    //         return dp[i][j]=solve(i-1,j-1,word1,word2,dp);
    //     }
    //     else{
    //         //insert
    //         int insert=1+solve(i,j-1,word1,word2,dp);
    //         int del=1+solve(i-1,j,word1,word2,dp);
    //         int replace=1+solve(i-1,j-1,word1,word2,dp);
    //         return dp[i][j]=min(insert,min(del,replace));
    //     }
    //     return -1;
    // }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return solve(word1.length()-1,word2.length()-1,word1,word2,dp);
        dp[0][0]=0;
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(del,replace));
                }
            }
        }
        return dp[n][m];
    }
};