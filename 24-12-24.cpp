class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;

        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 = 0;
        int diameter = 0;

        for (int neighbor :
             adjList[node]) {
            if (neighbor == parent)
                continue;

            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);

            diameter = max(diameter, childDiameter);

            depth++;
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
};