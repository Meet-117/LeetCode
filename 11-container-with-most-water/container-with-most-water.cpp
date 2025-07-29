class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left < right) {
            int high = min(height[left], height[right]);
            int width = right - left;
            maxArea = max(high * width, maxArea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};