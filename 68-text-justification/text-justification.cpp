class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string>ans;
        
        int i=0;
        while(i<n){
            int j=i;
            int letter=0;
            while(j<n && letter+words[j].size()+j-i<=maxWidth){
               letter+=words[j].size();
               j++;


            }
            int gaps=j-i-1;
            string line;
            if(j==n || gaps==0){
                for(int k=i;k<j;k++){
                    line+=words[k];
                    if(k!=j-1){
                        line+=" ";
                    }
                }
                while(line.size()<maxWidth)line+=" ";
            }
            else{
                int totalspaces=maxWidth-letter;
                int each=totalspaces/gaps;
                int extra=totalspaces%gaps;
                for(int k=i;k<j-1;k++){
                    line+=words[k];
                    int space=each+(extra>0);
                    line+= string(space,' ');
                    if(extra>0)extra--;
                    
                }
                line+=words[j-1];

            }
            ans.push_back(line);
            i=j;
        }
        return ans;

    }
};