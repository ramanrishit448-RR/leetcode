class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for (char c : s) {
            // If stack is not empty and top matches current char
            if (!res.empty() && res.back() == c) {
                res.pop_back(); // Remove the duplicate
            } else {
                res.push_back(c); // Add to stack
            }
        }
        return res;
    }
};