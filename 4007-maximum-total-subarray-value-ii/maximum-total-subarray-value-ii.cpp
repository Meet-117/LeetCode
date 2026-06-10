class Solution {

    struct PriorityNode {
        int i;
        int j;
        long long val;

        PriorityNode(int i, int j, long long val) {
            this->i = i;
            this->j = j;
            this->val = val;
        }
    };

    struct Compare {
        bool operator()(PriorityNode& a, PriorityNode& b) {
            return a.val < b.val;
        }
    };

    class SegmentTree {
        struct Node {
            int start;
            int end;
            int minValue;
            int maxValue;

            Node* left;
            Node* right;

            Node(int start, int end) {
                this->start = start;
                this->end = end;
                minValue = INT_MAX;
                maxValue = INT_MIN;
                left = nullptr;
                right = nullptr;
            }
        };

        Node* root;
        Node* buildTree(vector<int>& nums, int start, int end) {
            Node* node = new Node(start, end);

            if (start == end) {
                node->minValue = nums[start];
                node->maxValue = nums[start];
                return node;
            }

            int mid = (start + end) / 2;

            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);

            node->minValue = min(node->left->minValue, node->right->minValue);
            node->maxValue = max(node->left->maxValue, node->right->maxValue);

            return node;
        }

        pair<int, int> query(Node* node, int start, int end) {

            if (node == nullptr) {
                return {INT_MAX, INT_MIN};
            }

            if (start <= node->start && node->end <= end) {
                return {node->minValue, node->maxValue};
            }

            if (node->end < start || end < node->start) {
                return {INT_MAX, INT_MIN};
            }
            pair<int, int> left = query(node->left, start, end);
            pair<int, int> right = query(node->right, start, end);

            int minV = min(left.first, right.first);
            int maxV = max(left.second, right.second);

            return {minV, maxV};
        }

    public:
        SegmentTree(vector<int>& nums) {
            root = buildTree(nums, 0, nums.size() - 1);
        }

        pair<int, int> query(int start, int end) {
            return query(root, start, end);
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(nums);
        priority_queue<PriorityNode, vector<PriorityNode>, Compare> pq;

        for (int i = 0; i < n; i++) {
            int j = n - 1;
            pair<int, int> res = st.query(i, j);
            long long val = (long long)res.second - res.first;
            pq.push(PriorityNode(i, j, val));
        }

        long long ans = 0;

        while (k-- > 0) {
            PriorityNode peak = pq.top();
            pq.pop();

            ans += peak.val;

            int i = peak.i;
            int j = peak.j - 1;

            if (i <= j) {
                pair<int, int> res = st.query(i, j);
                long long val = (long long)res.second - res.first;
                pq.push(PriorityNode(i, j, val));
            }
        }

        return ans;
    }
};