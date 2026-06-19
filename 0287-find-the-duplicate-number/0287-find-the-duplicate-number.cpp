class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //initialize
        int slow = nums[0];
        int fast = nums[nums[0]];

        //intersection point
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        //find the enterace of the cycle
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};