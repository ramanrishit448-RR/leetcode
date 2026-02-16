class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freq;

        int i = 0;              // left pointer
        int j = 0;              // right pointer
        int maxFreq = 0;        // highest frequency in current window
        int result = 0;

        while (j < s.size()) {

            char ch = s[j];
            freq[ch]++;

            maxFreq = std::max(maxFreq, freq[ch]);

            // shrink window if invalid
                                        
            while ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }

            result = std::max(result, j - i + 1);
            j++;
        }

        return result;
    }
};

