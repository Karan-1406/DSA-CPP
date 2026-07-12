class Solution {
public:
    bool detect(int src, vector<vector<int>>& adj,
                vector<int>& vis, vector<int>& pathVis) {

        vis[src] = 1;
        pathVis[src] = 1;

        for (int i : adj[src]) {

            if (!vis[i]) {
                if (!detect(i, adj, vis, pathVis))
                    return false;
            }
            else if (pathVis[i]) {
                return false;
            }
        }

        pathVis[src] = 0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!detect(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};