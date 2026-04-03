class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty()) {
                // Check if the current char completes "AB" or "CD"
                if ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D')) {
                    st.pop(); // Remove the match
                    continue; // Skip pushing the current char
                }
            }
            st.push(c); // No match found, add to stack
        }

        return st.size();
    }
};