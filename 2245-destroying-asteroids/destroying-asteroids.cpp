class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long Mass = mass;
        for (int asteroid : asteroids) {
            if (Mass < asteroid) {
                return false;
            }
            Mass += asteroid;
        }
        return true;
    }
};