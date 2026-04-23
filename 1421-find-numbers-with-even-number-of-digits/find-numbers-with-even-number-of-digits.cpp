class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (evenDigitCount(nums[i])) {
                n++;
            }
        }
        return n;
    }

    bool evenDigitCount(int num) {
        int count = 0;
        while (num > 0) {
            num = num / 10;
            count++;
        }
        if (count % 2 == 0) {
            return true;
        }
        return false;
    }
};