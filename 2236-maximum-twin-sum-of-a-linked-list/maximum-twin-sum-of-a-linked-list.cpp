/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {

        int maxVal = INT_MIN;

        vector<int> nums;

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size();
        for (auto i{0uz}; i < n / 2; i++) {
            maxVal = max(maxVal, nums[i] + nums[n - i - 1]);
        }
        return maxVal;
    }
};