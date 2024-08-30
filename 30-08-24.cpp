class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int nodeCount,
                                           vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        long long currentShortestDistance =
            runDijkstra(edges, nodeCount, source, destination);

        if (currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        for (vector<int>& edge : edges) {
            if (edge[2] > 0) continue;

            edge[2] = matchesTarget ? INF : 1;

            if (!matchesTarget) {
                long long newDistance =
                    runDijkstra(edges, nodeCount, source, destination);
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return matchesTarget ? edges : vector<vector<int>>{};
    }
    
    long long runDijkstra(const vector<vector<int>>& edges, int nodeCount,
                          int sourceNode, int destinationNode) {
        vector<vector<long long>> adjMatrix(nodeCount,
                                            vector<long long>(nodeCount, INF));
        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        minDistance[sourceNode] = 0;

        for (const vector<int>& edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        for (int i = 0; i < nodeCount; ++i) {
            int nearestUnvisitedNode = -1;
            for (int j = 0; j < nodeCount; ++j) {
                if (!visited[j] &&
                    (nearestUnvisitedNode == -1 ||
                     minDistance[j] < minDistance[nearestUnvisitedNode])) {
                    nearestUnvisitedNode = j;
                }
            }
            visited[nearestUnvisitedNode] = true;

            for (int v = 0; v < nodeCount; ++v) {
                minDistance[v] =
                    min(minDistance[v], minDistance[nearestUnvisitedNode] +
                                            adjMatrix[nearestUnvisitedNode][v]);
            }
        }

        return minDistance[destinationNode];
    }
};