class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end(), comp);

        vector<pair<int, int>> sortedQueries;
        for(int i=0; i<queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<
        pair<int,int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > minHeap;

        vector<int> result(queries.size());
        int i=0;
        int n = intervals.size();

        for(auto& q: sortedQueries){
            int query = q.first;
            int index = q.second;

            while(i < n && intervals[i][0] <= query){
                int left = intervals[i][0];
                int right = intervals[i][1];
                int length = right - left + 1;

                minHeap.push({length, right});
                i++;
            }

            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }

            if(minHeap.empty()){
                result[index] = -1;
            }else{
                result[index] = minHeap.top().first;
            }
        }
        return result;
    }
};