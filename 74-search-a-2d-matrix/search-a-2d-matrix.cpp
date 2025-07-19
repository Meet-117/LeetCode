class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;

        int n = matrix[0].size();
        if (n == 0)
            return false;
        int begin = 0, end = m - 1, rope = 0;
        int found = -1;
        while (begin <= end) {
            rope = begin + (end - begin) / 2;

            if (matrix[rope][0] == target)
                return true;

            if (matrix[rope][0] < target) {
                if (rope == m - 1 || target < matrix[rope + 1][0]) {
                    found = rope;
                    break;
                }
                begin = rope + 1;
            } else {
                end = rope - 1;
            }
        }
        if (found == -1)
            return false;

        int left = 0, right = matrix[found].size() - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[found][mid] == target)
                return true;
            else if (matrix[found][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};