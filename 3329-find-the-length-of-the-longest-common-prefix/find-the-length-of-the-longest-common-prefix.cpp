class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[10];

        TrieNode() {
            for (int i = 0; i < 10; i++) {
                children[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;

        Trie() { root = new TrieNode(); }

        void insert(string pre) {

            TrieNode* node = root;

            for (char c : pre) {

                int n = c - '0';

                if (node->children[n] == nullptr) {
                    node->children[n] = new TrieNode();
                }

                node = node->children[n];
            }
        }

        int search(string s) {

            TrieNode* node = root;

            int count = 0;

            for (char c : s) {

                int n = c - '0';

                if (node->children[n] != nullptr) {
                    count++;
                    node = node->children[n];
                } else {
                    break;
                }
            }

            return count;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        Trie trie;

        for (int x : arr1) {
            trie.insert(to_string(x));
        }

        int maxm = 0;

        for (int x : arr2) {

            int len = trie.search(to_string(x));

            maxm = max(maxm, len);
        }

        return maxm;
    }
};