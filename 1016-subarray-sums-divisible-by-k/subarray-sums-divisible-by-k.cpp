class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int prefixSum = 0;
        
        // Using a map to store frequency of remainders
        unordered_map<int, int> counts;
        counts[0] = 1; // Base case: a prefix sum of 0 has appeared once

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            
            // Calculate remainder and normalize it to be positive
            int rem = prefixSum % k;
            if (rem < 0) {
                rem += k; 
            }
            
            // If this remainder has been seen before, it means there are 
            // 'counts[rem]' subarrays ending here that are divisible by k.
            res += counts[rem];
            
            // Update the frequency of this remainder
            counts[rem]++;
        }
        
        return res;
    }
};