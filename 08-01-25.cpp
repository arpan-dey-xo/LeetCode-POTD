class Node {
public:
    Node* links[26] = {};

    bool contains(char c) { return links[c - 'a'] != NULL; }

    void put(char c, Node* node) { links[c - 'a'] = node; }

    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->contains(c)) {
                node->put(c, new Node());
            }
            node = node->next(c);
        }
    }
    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) {
                return false;
            }
            node = node->next(c);
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            Trie prefixTrie, suffixTrie;

            prefixTrie.insert(words[i]);

            string revWord = words[i];
            reverse(revWord.begin(), revWord.end());
            suffixTrie.insert(revWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;

                string prefixWord = words[j];
                string revPrefixWord = prefixWord;
                reverse(revPrefixWord.begin(), revPrefixWord.end());

                if (prefixTrie.startsWith(prefixWord) &&
                    suffixTrie.startsWith(revPrefixWord)) {
                    count++;
                }
            }
        }

        return count;
    }
};