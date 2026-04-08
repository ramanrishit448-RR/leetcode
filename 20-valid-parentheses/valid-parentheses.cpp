class Solution {
public:
    bool isValid(string s) {
    stack<char> st;

for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '[' || ch == '{') {
        st.push(ch);   // push opening bracket
    } else {
        if (st.empty()) return false;

        char top = st.top();
        st.pop();

        if (ch == ')' && top != '(') return false;
        if (ch == ']' && top != '[') return false;
        if (ch == '}' && top != '{') return false;
    }
}

return st.empty();
    }
};