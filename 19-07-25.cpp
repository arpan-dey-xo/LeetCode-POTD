class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> result;

        for (string& f : folder) {
            bool isSubFolder = false;
            string prefix = f;
            while (!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos) break;

                prefix = prefix.substr(0, pos);
                if (folderSet.count(prefix)) {
                    isSubFolder = true;
                    break;
                }
            }
            if (!isSubFolder) {
                result.push_back(f);
            }
        }
        return result;
    }
};