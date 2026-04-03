

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s; // Stores indices

        // Loop twice to simulate circular array
        for (int i = 0; i < 2 * n; i++) {
            // While stack is not empty and current element is 
            // greater than the element at the index on top of stack
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            // Only push indices from the first pass
            if (i < n) {
                s.push(i);
            }
        }
        return res;
    }
};