// this is its template for leetcode 53 maximum subarray sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = -1e4;
        int ms = -1e4;
        for (int i = 0; i < nums.size(); i++) {
            cs = max(nums[i], cs + nums[i]);
            if (ms < cs) {
                ms = cs;
            }
        }
        return ms;
    }
};
