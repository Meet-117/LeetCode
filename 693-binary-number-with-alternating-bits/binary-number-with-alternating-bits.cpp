class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> v;
        while (n > 0) {
            v.push_back(n % 2);
            n = n / 2;
        }
        int flag = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }
        return true;
    }
};