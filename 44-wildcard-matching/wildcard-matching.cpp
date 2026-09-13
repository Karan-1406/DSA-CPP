class Solution {
public:
    // bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    //     if(i==0&&j==0)return true;
    //     if(j==0 &&i>0)return false;
    //     if(i==0 &&j>0){
            // for(int a=1;a<=j;a++){
            //     if(p[a-1]!='*')return false;
            // }
    //         return true;
    //     }
    // if(dp[i][j]!=-1)return dp[i][j];

    //     if(s[i-1]==p[j-1] || p[j-1]=='?')return dp[i][j]=f(i-1,j-1,s,p,dp);
    //     if(p[j-1]=='*')return dp[i][j]=f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
    //     return dp[i][j]=false;
    // }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        //if(n<m)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        dp[0][0]=true;
        for(int i=1;i<=n;i++)dp[i][0]=false;
        for(int j=1;j<=m;j++){
            int flag=true;
            for(int a=1;a<=j;a++){
                if(p[a-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else{
                    dp[i][j]=0;
                }
            }
        }
        //return f(n,m,s,p,dp);
        return dp[n][m];
    }
};