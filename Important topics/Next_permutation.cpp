class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int prev = nums[nums.size() - 1];
        bool check = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < prev) {
                check = true;
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
            prev = nums[i];
        }
        if (!check) {
            reverse(nums.begin(), nums.end());
        }
        return;
    }
};
