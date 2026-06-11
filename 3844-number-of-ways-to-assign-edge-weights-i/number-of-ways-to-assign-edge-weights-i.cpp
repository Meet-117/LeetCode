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
    long long powmod(long long base, long long exp, long long mod) {
        long long result = 1;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }

        return result;
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
        return (depth <= 1) ? 1 : powmod(2, depth - 1, mod);
    }
};