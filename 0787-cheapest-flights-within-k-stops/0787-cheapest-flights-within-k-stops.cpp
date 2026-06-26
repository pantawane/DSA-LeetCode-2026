class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int,int>>> adj;

        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v,w});
        }

        queue<pair<int, pair<int, int>>> q;
        //(stops, (node, dist))
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;
            for(auto neighbour: adj[node]){
                int nextNode = neighbour.first;
                int weight = neighbour.second;

                if(cost + weight < dist[nextNode] ){
                    dist[nextNode] = cost + weight;
                    q.push({stops + 1, {nextNode, cost+weight}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};