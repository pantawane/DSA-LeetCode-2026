class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> list;
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != element2){
                cnt1 = 1;
                element1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != element1){
                cnt2 = 1;
                element2 = nums[i];
            }
            else if(element1 == nums[i]) cnt1++;
            else if(element2 == nums[i]) cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }
        // manual check
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == element1) count1++;
            if(nums[i] == element2) count2++;
        }
        int mini = (int) n/3 + 1;
        if(count1 >= mini) list.push_back(element1);
        if(count2 >= mini) list.push_back(element2);

        return list;
    }
};