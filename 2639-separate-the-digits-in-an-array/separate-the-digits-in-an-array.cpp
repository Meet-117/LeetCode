class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);

            for (char c : str) {
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};