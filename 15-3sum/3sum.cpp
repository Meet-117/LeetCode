class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threesum;
        //Sort vector in non-decreasing order
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            //If duplicate found: continue
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            //Second pointer goes from left to right
            int j = i + 1;
            //Third pointer goes from right to left
            int k = nums.size() - 1;
            while (j < k) {
                int target = -nums[i];          //Fixing x
                int sum = nums[j] + nums[k];    //Setting up y and z
                if (target == sum) {
                    threesum.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])             //If duplicate found
                        j++;
                    while (j < k && nums[k] == nums[k - 1])             //If duplicate found
                        k--;
                    //Moving forward
                    j++;
                    k--;
                } else if (target > sum)
                    j++;
                else
                    k--;
            }
        }
        return threesum;
    }
};