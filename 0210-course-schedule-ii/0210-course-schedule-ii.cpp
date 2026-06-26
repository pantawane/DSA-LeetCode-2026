class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         //create adjecency list
        unordered_map<int, list<int>> adj;

        for(int i=0; i< prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a); //because b comes before a
        }

        //find all indegrees
        vector<int> indegree(numCourses);
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        //push all 0 indegree nodes into queue
        queue<int> q;
        for(int i=0; i< numCourses; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        // do bfs
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            //find all neighbour indegree updates
            for(auto neighbour: adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                q.push(neighbour);
            }

        }
        if(ans.size() == numCourses)
        return ans;

        return {};
    }
};