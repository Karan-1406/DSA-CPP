class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {

        vector<vector<int>> mat(m, vector<int>(n, 0));

        for(auto i : indices) {

            int r = i[0];
            int c = i[1];

            for(int j = 0; j < n; j++) {
                mat[r][j]++;
            }

            for(int j = 0; j < m; j++) {
                mat[j][c]++;
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] % 2 != 0)
                    cnt++;
            }
        }

        return cnt;
    }
};