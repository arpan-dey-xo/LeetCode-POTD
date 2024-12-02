class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int currentWordPosition = 1;
        int currentIndex = 0;
        int sentenceLength = sentence.length();

        while (currentIndex < sentenceLength) {
            while (currentIndex < sentenceLength &&
                   sentence[currentIndex] == ' ') {
                currentIndex++;
                currentWordPosition++;
            }

            int matchCount = 0;
            while (currentIndex < sentenceLength &&
                   matchCount < searchWord.length() &&
                   sentence[currentIndex] == searchWord[matchCount]) {
                currentIndex++;
                matchCount++;
            }

            if (matchCount == searchWord.length()) {
                return currentWordPosition;
            }

            while (currentIndex < sentenceLength &&
                   sentence[currentIndex] != ' ') {
                currentIndex++;
            }
        }
        return -1;
    }
};