class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    // Helper function to count subarrays with AT MOST k distinct integers
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, count = 0;
        long long result = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            // Expand the window
            if (freq[nums[right]] == 0) {
                count++;
            }
            freq[nums[right]]++;
            right++;

            // Shrink the window if distinct elements exceed k
            while (count > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    count--;
                }
                left++;
            }

            // The number of subarrays ending at 'right-1' is (right - left)
            result += (right - left);
        }
        return result;
    }
};