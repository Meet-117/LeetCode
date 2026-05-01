class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long currentSum = 0;
        long long numsTotal = 0;
        long long maxNumber;
        for (int i = 0; i < n; i++) {
            numsTotal += nums[i];
            currentSum += nums[i] * (long long)i;
        }

        maxNumber = currentSum;

        for (int k = 1; k < n; k++) {
            currentSum = currentSum + numsTotal - (long long)n * nums[n - k];
            maxNumber = max(maxNumber, currentSum);
        }
        return (int)maxNumber;
    }
};