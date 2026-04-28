class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> expected = sortedArray(heights);
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }
        return count;
    }

    vector<int> sortedArray(vector<int> heights) {
        sort(heights.begin(), heights.end());
        return heights;
    }
};