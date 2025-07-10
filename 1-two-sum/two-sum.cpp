class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hashmap method
        unordered_map<int, int> theMap;                     //Hashmap stores complement and its index
        for (int i = 0; i < nums.size(); i++) {
            int partner = target - nums[i];                 //Find complement of given number with target
            if (theMap.find(partner) != theMap.end()) {     //If we have already stored the complement, findit
                return {theMap[partner], i};                //and return its index
            }
            theMap[nums[i]] = i;                            //If not, save it to the Map
        }
        return {};
    }
};