class Solution {
public:
    vector<int> topological_sort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> in_degree(n, 0);
        vector<int> topo;

        // Calculate in-degrees of all vertices
        for (int i = 0; i < n; ++i) {
            for (int v : adj[i]) {
                in_degree[v]++;
            }
        }

        // Queue for vertices with no incoming edges
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's algorithm
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> topo = topological_sort(adj);
        vector<vector<int>> res(n);

        // Create ancestor list for each node
        vector<set<int>> ancestors(n);

        for (int u : topo) {
            for (int v : adj[u]) {
                ancestors[v].insert(u);
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
            }
        }

        for (int i = 0; i < n; ++i) {
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return res;
    }
};
