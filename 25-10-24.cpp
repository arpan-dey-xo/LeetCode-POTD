class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string lastFolder = result.back();
            lastFolder += '/';

            if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                result.push_back(folder[i]);
            }
        }

        return result;
    }
};