class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> list;
        int n = nums.size();
        unordered_map<int, int> mp;
        int minElement = n / 3 + 1;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;

            if(mp[nums[i]] == minElement){
                list.push_back(nums[i]);
            }
        }
        return list;
    }
};