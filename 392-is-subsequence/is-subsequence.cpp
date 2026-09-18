class Solution {
public:
    bool f(int i,int j,string &s, string&t){
        //if(i==0)return s[0]==t[j];
        if(i<0)return true;
        if(j<0)return false;
        if(s[i]==t[j])return f(i-1,j-1,s,t);
        
        return f(i,j-1,s,t);
    }
    bool isSubsequence(string s, string t) {
        return f(s.length()-1,t.length()-1,s,t);
    }
};