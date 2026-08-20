class Solution {
public:
    
    // int solve(int n,vector<int>&dp){
    //     if(n<=1)return n;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
        
    // }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        //return solve(n,dp);
        if(n<=1)return n;
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        int prev=1,sprev=0;
        //int cur=0;
        for(int i=2;i<=n;i++){
            //cur=prev+sprev;
            if(i==n)return prev+sprev;
            int temp=prev+sprev;
            sprev=prev;
            prev=temp;
            
            
        }
        return -1;
    }
};