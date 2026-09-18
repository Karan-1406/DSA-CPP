class Solution {
public:
    bool f(int i,int j,string &s, string&t,vector<vector<int>>&dp){
        //if(i==0)return s[0]==t[j];
        if(i<0)return true;
        if(j<0)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return f(i-1,j-1,s,t,dp);
        
        return dp[i][j]=f(i,j-1,s,t,dp);
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(s.length()-1,t.length()-1,s,t,dp);
    }
};