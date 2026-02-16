class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long sum = 0, i=0, j=0, result=0;

        while(j< nums.size()){
            sum = sum + nums[j];
            while(long(nums[j]) * (j-i+1) - sum > k){
                sum = sum - nums[i];
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};