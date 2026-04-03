class Solution {
public:
    string makeGood(string s) {
        string result = "";
        
        for (char c : s) {
            // If the stack is not empty and the current char 'c' 
            // makes a "bad" pair with the top of the stack
            if (!result.empty() && abs(result.back() - c) == 32) {
                // "Undo" the previous operation by removing the last character
                result.pop_back();
            } else {
                // Otherwise, add the current character to our "good" string
                result.push_back(c);
            }
        }
        
        return result;
    }
};