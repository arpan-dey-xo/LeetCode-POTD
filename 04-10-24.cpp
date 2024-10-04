class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size();
        long long totalChemistry = 0;

        int targetTeamSkill = skill[0] + skill[n - 1];

        for (int i = 0; i < n / 2; i++) {
            int currentTeamSkill = skill[i] + skill[n - i - 1];

            if (currentTeamSkill != targetTeamSkill) {
                return -1;
            }

            totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
        }

        return totalChemistry;
    }
};