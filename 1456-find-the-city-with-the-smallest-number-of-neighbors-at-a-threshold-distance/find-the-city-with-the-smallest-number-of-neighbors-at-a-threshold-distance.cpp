class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int minReachable = INT_MAX;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= minReachable) {
                minReachable = cnt;
                ans = i;      // larger index wins on tie
            }
        }

        return ans;
    }
};