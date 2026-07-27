class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = grid[i][j];
                if(a==0)continue;
                ans += 4 * a + 2;
                if (i > 0) {

                    if (grid[i - 1][j] != 0) {
                        ans -= 2 * min(grid[i - 1][j], grid[i][j]);
                    }
                }
                if (j > 0) {
                    if (grid[i][j - 1] != 0) {
                        ans -= 2 * min(grid[i][j], grid[i][j - 1]);
                    }
                }
            }
        }
        return ans;
    }
};