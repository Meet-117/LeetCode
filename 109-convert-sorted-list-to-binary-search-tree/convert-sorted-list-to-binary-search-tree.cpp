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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        vector<int> v = listToVector(head);
        return build(v, 0, v.size() - 1);
    }

    TreeNode* build(vector<int>& v, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* newNode = new TreeNode(v[mid]);

        newNode->left = build(v, left, mid - 1);
        newNode->right = build(v, mid + 1, right);

        return newNode;
    }
    vector<int> listToVector(ListNode* head) {
        vector<int> v;
        ListNode* current = head;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next;
        }
        return v;
    }
};