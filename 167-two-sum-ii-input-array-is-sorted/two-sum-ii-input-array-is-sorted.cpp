class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int n = numbers[i];
            int left = i + 1;
            int right = numbers.size() - 1;
            int partner = target - n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == partner) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < partner) {
                    left = mid + 1;
                } else if (numbers[mid] > partner) {
                    right = mid - 1;
                }
            }
        }
        return {-1, -1};
    }
};