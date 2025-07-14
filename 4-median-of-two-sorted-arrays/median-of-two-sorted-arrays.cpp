class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int arr[n];
        for (int i = 0; i < n1; i++) {
            arr[i] = nums1[i];
        }
        for (int i = 0; i < n2; i++) {
            arr[n1 + i] = nums2[i];
        }
        for (int i = 0; i < n; i++) {
            bool x = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    x = true;
                }
            }
            if (x == false) {
                break;
            }
        }
        if (n % 2 == 1) {
            return arr[n / 2];
        } else {
            double r = (double)arr[n / 2];
            double s = (double)arr[(n / 2) - 1];
            return (r + s) / 2;
        }
    }
};