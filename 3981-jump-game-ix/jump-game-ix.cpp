class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preMax(n);
        int sufMin = INT_MAX;

        preMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (preMax[i] > sufMin) {
                if (i + 1 < n) {
                    ans[i] = ans[i + 1];
                } else {
                    ans[i] = preMax[i];
                }
            } else {
                ans[i] = preMax[i];
            }
            sufMin = min(sufMin, nums[i]);
        }
        return ans;
    }
};