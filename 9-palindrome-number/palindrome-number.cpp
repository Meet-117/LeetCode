class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int a = x, b;
        long long sum = 0;
        while (a > 0) {
            b = a % 10;
            sum = (sum * 10) + b;
            a /= 10;
        }
        if (sum == x) {
            return true;
        }
        return false;
    }
};