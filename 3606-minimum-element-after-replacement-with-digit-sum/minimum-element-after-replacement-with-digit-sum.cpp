class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int minm = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            while (nums[i] > 0) {
                int a = nums[i] % 10;
                sum += a;

                nums[i] = nums[i] / 10;
            }
            minm = min(minm, sum);
        }
        return minm;
    }
};