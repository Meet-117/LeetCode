class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int n = A.size();
        vector<int> freq(n, 0);
        for (int i = 0; i < n; i++) {
            freq[A[i] - 1]++;
            freq[B[i] - 1]++;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (freq[j] == 2) {
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};