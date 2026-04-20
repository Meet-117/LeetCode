class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int left = colors[0];
        int right = colors[n - 1];
        int leftMax = 0;
        int rightMax = 0;

        for (int i = 0; i < n; i++) {
            if (left != colors[i]) {
                leftMax = max(leftMax, i);
            }
            if (right != colors[i]) {
                rightMax = max(rightMax, n - i - 1);
            }
        }
        return max(leftMax, rightMax);
    }
};