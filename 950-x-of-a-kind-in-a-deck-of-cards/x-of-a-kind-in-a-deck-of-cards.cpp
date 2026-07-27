class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int,int>hash;
        int g=0;
        for(int i=0;i<n;i++){
            hash[deck[i]]++;
            
        }
        for(auto it:hash){
            g=gcd(g,it.second);
        }
        return g>=2;
        
    }
};