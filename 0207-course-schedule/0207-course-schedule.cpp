class Solution {
private:
    bool cycleDFS(int node, vector<bool> &visited,  vector<bool> &dfsVisited,
    unordered_map<int, list<int>> &adj){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleDected = cycleDFS(neighbour, visited, dfsVisited, adj);
                if(cycleDected){
                    return true;
                }
            }else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create adjecency list
        unordered_map<int, list<int>> adj;

        for(int i=0; i< prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a); //because b comes before a
        }

        //do dfs calls for all other nodes
       // unordered_map<int, bool> visited;
        //unordered_map<int, bool> dfsVisited;
        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool cycleFound = cycleDFS(i, visited, dfsVisited, adj);
                if(cycleFound){
                    return false;
                }
            }
        }
        return true;
    }
};