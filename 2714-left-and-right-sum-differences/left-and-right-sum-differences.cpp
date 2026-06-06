class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sumLeft = 0;
        vector<int> ans;
        int total = accumulate(nums.begin(), nums.end(), 0);
        for (size_t i{}; i < nums.size(); ++i) {

            total -= nums[i];
            ans.push_back(abs(total - sumLeft));
            sumLeft += nums[i];
        }
        return ans;
    }
};