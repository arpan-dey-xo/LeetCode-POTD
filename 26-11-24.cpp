class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto edge : edges) {
            indegree[edge[1]]++;
        }

        int champ = -1, champCount = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                champCount++;
                champ = i;
            }
        }

        return champCount > 1 ? -1 : champ;
    }
};