class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr1.size();i++){
            if(mpp.find(arr1[i])!=mpp.end()){
                mpp[arr1[i]]+=1;
            }
            else{
                mpp[arr1[i]]=1;
            }
        }
        vector<int>ans;
       for(int it:arr2){
        while(mpp[it]!=0){
            ans.push_back(it);
            mpp[it]--;
        }
        mpp.erase(it);
        

       }
       vector<int>rem;
       for(auto it:mpp){
        while(it.second!=0){
        rem.push_back(it.first);
        it.second--;
        }
       }
       sort(rem.begin(),rem.end());
       for(int i:rem){
        ans.push_back(i);
       }

        return ans;

    }
};