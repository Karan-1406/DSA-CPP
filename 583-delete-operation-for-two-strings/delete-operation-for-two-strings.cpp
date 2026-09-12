class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        //vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //return solve(n-1,m-1,text1,text2,dp);
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int i=0;i<=m;i++)prev[i]=0;
        //for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])cur[j]=1+prev[j-1];
                else{
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return n+m-2*prev[m];
    }
};