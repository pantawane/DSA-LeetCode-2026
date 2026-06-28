class Solution {
public:
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent, parent[node]);
    }

    void Union(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (findParent(parent, u) == findParent(parent, v))
                return edge;

            Union(u, v, parent, rank);
        }

        return {};
    }
};