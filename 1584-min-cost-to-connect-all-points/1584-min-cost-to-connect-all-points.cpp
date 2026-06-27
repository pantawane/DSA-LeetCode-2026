class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        //create priority queue min heap
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //create visited array
        vector<bool> visited(n, false);
        int minCost = 0;

        pq.push({0,0}); // inital push node and weight

        while(!pq.empty()){
            auto p = pq.top();
            int weight = p.first;
            int node = p.second;
            pq.pop();

            if(visited[node]) continue;

            visited[node] = true;
            minCost += weight;

            for(int i=0; i<n; i++){
                if(!visited[i]){
                    int newWeight = manDist(points, node, i);
                    pq.push({newWeight, i});
                }
            }
        }

        return minCost;
    }
};