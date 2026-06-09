class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxV = LLONG_MIN, minV = LLONG_MAX;

        for (auto i{0uz}; i < nums.size(); ++i) {
            maxV = max((long long)nums[i], maxV);
            minV = min((long long)nums[i], minV);
        }
        return (maxV - minV) * k;
    }
};