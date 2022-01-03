//Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int n =nums.size();
        int sum =0;
        while(j<n){
            sum+=nums[j++];
            while(sum>=target){
                sum-=nums[i++];
                ans = min(ans,j-i+1);
            }
        }
        return ans == INT_MAX?0:ans;
        
    }
};