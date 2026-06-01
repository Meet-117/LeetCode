class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int count = 0;
        sort(cost.begin(), cost.end(), greater<>());

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 == 0)
                continue;
            count += cost[i];
        }
        return count;
    }
};