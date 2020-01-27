/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int water = 0;
        int lMax = 0;
        int rMax = 0;
        
        while (l < r) {
            if (height[l] < height[r]) {
                height[l] >= lMax ? (lMax = height[l]) : water += (lMax - height[l]);
                l++;
            } else {
                height[r] >= rMax ? (rMax = height[r]) : water += (rMax - height[r]);
                r--;
            }
        }

    return water;     
    }
};