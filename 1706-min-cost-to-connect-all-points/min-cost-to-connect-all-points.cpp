class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        vector<int> visited(n, 0);

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, 0, -1});

        int sum = 0;

        while(!pq.empty()) {

            int w = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];
            pq.pop();

            if(visited[node]) continue;

            visited[node] = 1;
            sum += w;

            for(auto it : adj[node]) {

                int nextnode = it.first;
                int nxtwt = it.second;

                if(!visited[nextnode]) {
                    pq.push({nxtwt, nextnode, node});
                }
            }
        }

        return sum;
    }
};