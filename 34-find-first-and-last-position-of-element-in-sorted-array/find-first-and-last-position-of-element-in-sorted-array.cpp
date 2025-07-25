class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        vector<int> result = {-1, -1};

        while(left <= right) {
            mid = left + (right - left)/2;
            if(nums[mid] == target) {
                result[0] = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        mid = 0;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(nums[mid] == target) {
                result[1] = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return {result[0], result[1]};
    }
};