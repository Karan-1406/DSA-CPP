class Solution {
    class DisjointSet{
        public:
        vector<int>rank,parent,size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int findUPar(int node){
                if(node==parent[node])return node;
                return parent[node]=findUPar(parent[node]);
        }
            void unionbyrank(int u,int v){
                int ulp_u=findUPar(u);
                int ulp_v=findUPar(v);
                if(ulp_u==ulp_v)return;
                else if(rank[ulp_u]<rank[ulp_v])parent[ulp_u]=ulp_v;
                else if(rank[ulp_u]>rank[ulp_v])parent[ulp_v]=ulp_u;
                else{
                    parent[ulp_v]=parent[ulp_u];
                    rank[ulp_u]++;
                }
            }
            void unionbysize(int u,int v ){
                int ulp_u=findUPar(u);
                int ulp_v=findUPar(v);
                if(ulp_u==ulp_v)return;
                if(size[ulp_u]<size[ulp_v]){
                    parent[ulp_u]=ulp_v;
                    size[ulp_v]+=size[ulp_u];
                }
                else{
                    parent[ulp_v]=ulp_u;
                    size[ulp_u]+=size[ulp_v];
                }

            }
        
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0,maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>stonenodes;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.unionbysize(row,col);
            stonenodes[row]=1;
            stonenodes[col]=1;
        }
        int cnt=0;
        for(auto it:stonenodes){
            if(ds.findUPar(it.first)==it.first)cnt++;
        }
        return stones.size()-cnt;
    }
};