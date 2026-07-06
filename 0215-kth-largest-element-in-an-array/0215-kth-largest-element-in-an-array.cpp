class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //create a min heap
        priority_queue<int, vector<int>, greater<int> > pq;

        //push 1st k elements in a pq
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }

        //rest k to n-1 elememts
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};