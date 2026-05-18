class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> m;
        queue<int> q;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            m[arr[i]].push_back(i);
        }

        q.push(0);
        visited[0] = true;
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {

                int i = q.front();
                q.pop();

                if (i == n - 1) {
                    return steps;
                }
                if (i - 1 >= 0 && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = true;
                }
                if (i + 1 < n && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = true;
                }
                for (int j = 0; j < m[arr[i]].size(); j++) {
                    if (visited[m[arr[i]][j]] == false) {
                        q.push(m[arr[i]][j]);
                        visited[m[arr[i]][j]] = true;
                    }
                }
                m[arr[i]].clear();
            }
            steps++;
        }
        return -1;
    }
};