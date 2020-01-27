/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        
        for (int i = 0; i < nums.size(); i++) {
            if (numsMap.find(target-nums[i]) != numsMap.end())
                return { numsMap[target-nums[i]], i };
            numsMap[nums[i]] = i;
        }

        return {};
    }
};