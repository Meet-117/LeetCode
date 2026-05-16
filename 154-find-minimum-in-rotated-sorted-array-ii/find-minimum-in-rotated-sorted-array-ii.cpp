class Solution {
public:
    int findMin(vector<int>& nums) {
        int minm = INT_MAX;

        for (auto it : nums) {
            minm = min(minm, it);
        }
        return minm;
    }
};