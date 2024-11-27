class Solution {
public:
    int findMinDistance(vector<vector<int>> &adjList, int n, int currentNode,
                        vector<int> &dp) {
        if (currentNode == n - 1) return 0;

        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList[currentNode]) {
            minDistance =
                min(minDistance, findMinDistance(adjList, n, neighbor, dp) + 1);
        }

        return dp[currentNode] = minDistance;
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> dp(n, -1);
        vector<vector<int>> adjList(n, vector<int>(0));

        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        vector<int> answer;

        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];

            adjList[u].push_back(v);

            answer.push_back(findMinDistance(adjList, n, 0, dp));

            dp.clear();
            dp.resize(n, -1);
        }

        return answer;
    }
};