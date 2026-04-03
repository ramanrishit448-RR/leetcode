

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string res = "";
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                // Handle multi-digit numbers (e.g., "100")
                int count = 0;
                while (isdigit(s[i])) {
                    count = 10 * count + (s[i] - '0');
                    i++;
                }
                counts.push(count);
            } else if (s[i] == '[') {
                // Push the string built so far and reset it for the new bracket level
                resultStack.push(res);
                res = "";
                i++;
            } else if (s[i] == ']') {
                // Pop the current level's multiplier and the previous level's string
                string temp = res;
                res = resultStack.top();
                resultStack.pop();
                
                int repeatTimes = counts.top();
                counts.pop();
                
                // Append the repeated current level string to the previous level
                while (repeatTimes--) {
                    res += temp;
                }
                i++;
            } else {
                // Regular characters
                res += s[i];
                i++;
            }
        }
        return res;
    }
};