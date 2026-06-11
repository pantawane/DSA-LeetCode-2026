class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1 count frequency
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num]++;
        }

        //step 2 create Max Heap(Priority Queue) frequency->number
        priority_queue<pair<int, int>> pq;
        for(auto it: freq){
            pq.push({it.second, it.first});
        }

        //step 3 extract top k elements
        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;  
    }

};