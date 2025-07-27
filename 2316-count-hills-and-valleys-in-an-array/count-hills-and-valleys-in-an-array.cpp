class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int hvCount = 0;
        int leftElement = nums[0];                  //Last non-duplicate to the left
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == leftElement) {
                continue;
            }
            int rightElement = -1;                  //Finding first duplicate to the right
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] != nums[j]) {
                    rightElement = nums[j];
                    break;
                }
            }
            //When the first non-duplicate to the right is found
            if (rightElement != -1) {
                if (leftElement < nums[i] && nums[i] > rightElement) {
                    hvCount++;
                } else if (leftElement > nums[i] && nums[i] < rightElement) {
                    hvCount++;
                }
            }
            //Updating left non-duplicating element
            leftElement = nums[i];
        }
        return hvCount;
    }
};