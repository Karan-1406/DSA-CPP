class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({1, {0, 0}});
        distance[0][0] = 1;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int i = 0; i < 8; i++) {
                int r = row + drow[i];
                int c = col + dcol[i];
                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0 &&
                    distance[r][c] > dist + 1) {
                    pq.push({dist + 1, {r, c}});
                    distance[r][c] = dist + 1;
                }
            }
        }
        
        return distance[n - 1][n - 1] == INT_MAX ? -1 : distance[n - 1][n - 1];
    }
};