class Solution {
public:
    int dfs(vector<vector<int>>& adjacencyList, int current, int parent) {
        int depth = 0;

        for (auto adjacentNode : adjacencyList[current]) {
            if (adjacentNode == parent)
                continue;

            depth = max(depth, dfs(adjacencyList, adjacentNode, current) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1e9 + 7;
        vector<vector<int>> adjacencyList(edges.size() + 2);

        for (auto edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        int depth = dfs(adjacencyList, 1, 0);
        long long ans = 1;
        for (int i = 1; i < depth; i++) {
            ans = (ans * 2) % mod;
        }
        return (int)ans;
    }
};