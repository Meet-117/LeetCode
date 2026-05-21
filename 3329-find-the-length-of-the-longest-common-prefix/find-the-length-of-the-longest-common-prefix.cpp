class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxm = 0;
        int n = arr1.size();
        int m = arr2.size();
        set<string> s;
        for (int i = 0; i < n; i++) {
            string s1 = to_string(arr1[i]);
            for (int j = 0; j < s1.length(); j++) {
                s.insert(s1.substr(0, j + 1));
            }
        }

        for (int i = 0; i < m; i++) {
            string s2 = to_string(arr2[i]);
            int found = 0;
            for (int j = 0; j < s2.length(); j++) {
                string sub = s2.substr(0, j + 1);
                if (s.find(sub) != s.end()) {
                    found = sub.length();
                }
                maxm = max(maxm, found);
            }
        }
        return maxm;
    }
};