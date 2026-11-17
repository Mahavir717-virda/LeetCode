class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {
        if (visited[u]) {
            return;
        }

        visited[u] = true;
        for (auto& v : adj[u]) {
            if (!visited[v]) {
                DFS(v, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (isConnected[u][v] == 1) {
                    adj[u].push_back(v);
                }
            }
        }
        int cnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }
};