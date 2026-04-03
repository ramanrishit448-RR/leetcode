class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int n = nums.size();
        
        for (int num : nums) {
            counts[num]++;
            // Check if this element has become the majority
            if (counts[num] > n / 2) {
                return num;
            }
        }
        
        return -1; // Should never reach here based on constraints
    }
};