class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0) {
            return;
        }
        vector<int> v(m + n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(j < m && k < n)
        {
            if(nums1[j] > nums2[k])
            {
                v[i++] = nums2[k++];
            }
            else if(nums1[j] < nums2[k])
            {
                v[i++] = nums1[j++];
            }
            else if(nums1[j] == nums2[k])
            {
                v[i++] = nums1[j++];
                v[i++] = nums2[k++];
            }
        }
        while(j < m)
        {
            v[i++] = nums1[j++];
        }
        while(k < n)
        {
            v[i++] = nums2[k++];
        }
        nums1 = v;
    }
};