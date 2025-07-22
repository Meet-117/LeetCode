class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;

        if (nums[left] <= nums[right]) {
            return nums[left];
        }
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            } else if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            if (nums[mid] < nums[right]) {
                right = mid - 1;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
        }
        return -1;
    }
};