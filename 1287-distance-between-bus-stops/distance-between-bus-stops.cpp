class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n=distance.size();
        //int ans;
        int clk=0;
        int aclk=0;
        int i=start;
        while(i!=destination){
            clk+=distance[i];
            i=(i+1)%n;
        }
        i=start;
        while(i!=destination){
            i=(i-1+n)%n;
            aclk+=distance[i];
        }
        return min(clk,aclk);
    }
};