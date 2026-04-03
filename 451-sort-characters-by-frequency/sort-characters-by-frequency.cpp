
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Push frequencies into a Max-Heap
        // We store pairs of {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (auto const& [ch, count] : freq) {
            pq.push({count, ch});
        }

        // Step 3: Build the result string
        string result = "";
        while (!pq.empty()) {
            pair<int, char> top = pq.top();
            pq.pop();
            // Append the character 'count' times to the result
            result.append(top.first, top.second);
        }

        return result;
    }
};