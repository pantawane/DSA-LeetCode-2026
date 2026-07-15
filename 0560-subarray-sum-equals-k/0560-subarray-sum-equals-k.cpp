class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // <prefixSum, freq>
        unordered_map<long long, int> preSumMap;

        preSumMap[0] = 1;

        long long sum = 0;
        int cnt = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            
            if(preSumMap.find(sum - k) != preSumMap.end()){
                cnt += preSumMap[sum - k];
            }
            preSumMap[sum]++;
        }
        return cnt;
    }
};