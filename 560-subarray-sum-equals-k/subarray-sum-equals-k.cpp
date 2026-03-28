class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;

        int prefixSum = 0, res = 0;

        for (int num : nums) {
            prefixSum += num;
            res += counts[prefixSum - k];  // works even if key not present (returns 0)
            counts[prefixSum]++;
        }

        return res;
    }
};