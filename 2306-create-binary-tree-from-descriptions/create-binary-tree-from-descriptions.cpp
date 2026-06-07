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

    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parent2Children,
                  int val) {

        TreeNode* node = new TreeNode(val);
        if (parent2Children.find(val) != parent2Children.end()) {
            for (auto& child : parent2Children[val]) {
                int num = child.first;
                bool isLeft = child.second;

                if (isLeft) {
                    node->left = dfs(parent2Children, num);
                } else {
                    node->right = dfs(parent2Children, num);
                }
            }
        }
        return node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, bool>>> parent2Children;
        unordered_set<int> allNodes;
        unordered_set<int> childNodes;

        for (auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            parent2Children[parent].push_back({child, isLeft});

            allNodes.insert(parent);
            allNodes.insert(child);
            childNodes.insert(child);
        }

        int root = 0;
        for (int node : allNodes) {
            if (childNodes.contains(node) == false) {
                root = node;
                break;
            }
        }

        return dfs(parent2Children, root);
    }
};