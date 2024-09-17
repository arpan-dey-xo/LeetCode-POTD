class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string A, std::string B) {
        std::unordered_map<std::string, int> count;
        std::stringstream ssA(A), ssB(B);
        std::string word;
        
        while (ssA >> word) {
            count[word]++;
        }
        
        while (ssB >> word) {
            count[word]++;
        }

        std::vector<std::string> ans;
        
        for (const auto& entry : count) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }
        
        return ans;
    }
};