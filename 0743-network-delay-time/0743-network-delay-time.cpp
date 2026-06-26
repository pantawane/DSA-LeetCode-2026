class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create adjacency list
        unordered_map<int, list<pair<int, int>> > adj;

        for(int i=0; i< times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        //distance array
        vector<int> dist(n+1, INT_MAX);

        //set
        set<pair<int, int>> st;
        dist[k] = 0;
        st.insert({0, k});

        while(!st.empty()){
            //fetch the record
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            st.erase(st.begin());

            //traverse neighbour
            for(auto neighbour: adj[topNode]){
                int nextNode = neighbour.first;
                int weight = neighbour.second;

                if(nodeDistance + weight < dist[nextNode]){
                    auto record = st.find({dist[nextNode], nextNode});
                    if(record != st.end()){
                        st.erase(record);
                    }
                    //update new record
                    dist[nextNode] = nodeDistance + weight;
                    st.insert({dist[nextNode], nextNode});
                }
            }
        }
            //find maximum distance
            int ans = 0;

            for(int i=1; i<=n; i++){
                if(dist[i] == INT_MAX)
                return -1;

                ans = max(ans, dist[i]);
            }
        return ans;
    }
};