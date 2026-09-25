class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 2;
        for (int i = 0; i < n - 1; i++) {
            map<pair<int, int>, int> mpp;
            int duplicate = 1;
            int curmax = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if (dx == 0)
                    dy = 1;
                if (dy == 0)
                    dx = 1;
                curmax = max(curmax, ++mpp[{dy, dx}]);
            }
            ans = max(ans, curmax + duplicate);
        }
        return ans;
        //     for(auto it:mpp){
        //         if(it.second>maxi)maxi=it.second;
        //     }
        //    }
        return ans;
    }
};