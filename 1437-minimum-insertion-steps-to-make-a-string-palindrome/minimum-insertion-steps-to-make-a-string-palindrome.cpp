class Solution {
public:
    int minInsertions(string s) {
         int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        int m=rev.length();
        vector<int>prev(m+1,0),cur(m+1,0);
        for(int i=0;i<=m;i++)prev[i]=0;
        //for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                if(s[i-1]==rev[j-1])cur[j]=1+prev[j-1];
                else{
                    cur[j]=max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return n-prev[m];
    }
};