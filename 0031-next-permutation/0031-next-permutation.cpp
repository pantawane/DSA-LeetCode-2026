class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;

        // Step 1: Find pivot
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // If already the last permutation
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find next greater element
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};