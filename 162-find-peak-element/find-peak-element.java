class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if (n == 1)
            return 0; //Only 1 element

        if (nums[0] > nums[1])
            return 0; //First element is peak

        if (nums[n - 1] > nums[n - 2])
            return n - 1; //Last element is peak

        int left = 1;
        int right = n - 2; //Avoiding edges
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else if (nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            }
        }
        return -1;
    }
}