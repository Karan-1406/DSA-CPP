class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i==0&&j==0)return true;
        if(j==0 &&i>0)return false;
        if(i==0 &&j>0){
            for(int a=1;a<=j;a++){
                if(p[a-1]!='*')return false;
            }
            return true;
        }
    if(dp[i][j]!=-1)return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?')return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j-1]=='*')return dp[i][j]=f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        //if(n<m)return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};