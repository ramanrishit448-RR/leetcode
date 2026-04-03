class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";
        
        // Store all characters present in the current string
        unordered_set<char> charSet(s.begin(), s.end());
        
        for (int i = 0; i < s.length(); i++) {
            // Check if both cases of the current character exist
            if (charSet.count(tolower(s[i])) && charSet.count(toupper(s[i]))) {
                continue;
            }
            
            // If not, s[i] is a 'breaker'. Split and recurse.
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1));
            
            // Return the longer one. If tied, return the earlier one (s1).
            return s1.length() >= s2.length() ? s1 : s2;
        }
        
        // If the loop finishes, the entire string is nice.
        return s;
    }
};