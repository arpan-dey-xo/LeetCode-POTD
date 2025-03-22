class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n);
    
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
    
            int completeCount = 0;
            unordered_set<int> visited;
    
            for (int vertex = 0; vertex < n; vertex++) {
                if (visited.count(vertex)) continue;
    
                int componentInfo[2] = {0, 0};
                dfs(vertex, graph, visited, componentInfo);
    
                if (componentInfo[0] * (componentInfo[0] - 1) == componentInfo[1]) {
                    completeCount++;
                }
            }
            return completeCount;
        }
    
    private:
        void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited,
                 int componentInfo[2]) {
            visited.insert(curr);
            componentInfo[0]++;
            componentInfo[1] +=
                graph[curr].size();
    
            for (int next : graph[curr]) {
                if (!visited.count(next)) {
                    dfs(next, graph, visited, componentInfo);
                }
            }
        }
    };