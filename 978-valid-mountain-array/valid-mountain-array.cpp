class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int maxVal = arr[0];
        int maxIndex = 0;
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
                maxIndex = i;
            }
        }
        if (maxIndex == 0 || maxIndex == n - 1) {
            return false;
        }
        for (int i = 1; i <= maxIndex; i++) {
            if (arr[i] <= arr[i - 1]) {
                return false;
            }
        }
        for (int i = maxIndex + 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
};