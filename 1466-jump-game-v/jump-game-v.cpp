class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];

        int best = 1;
        int n = arr.size();

        for (int next = i + 1; next <= min(n - 1, i + d); next++) {
            if (arr[next] >= arr[i])
                break;

            best = max(best, 1 + dfs(next, arr, d, dp));
        }

        for (int next = i - 1; next >= max(0, i - d); next--) {
            if (arr[next] >= arr[i])
                break;

            best = max(best, 1 + dfs(next, arr, d, dp));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};