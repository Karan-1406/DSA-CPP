class Solution {
public:
    bool compare(string a,string b){
        
        int n=a.length();
        int m=b.length();
        if(n!=m+1)return false;
        int i=0,j=0;
        while(i<n){
            if(j<m && a[i]==b[j]){
                i++;
                j++;
            }
            else i++;
        } 
        return j==m;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int maxi=1;
        sort(words.begin(), words.end(),
         [](string &a, string &b){
         return a.size() < b.size();
        });
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                maxi=max(maxi,dp[i]);
            }
        }
    return maxi;
    }
};