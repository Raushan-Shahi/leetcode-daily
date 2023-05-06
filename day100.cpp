// We will use the example given in the problem statement to demonstrate. As shown in the figure below, 
// we have found a total of 4 subsequences that satisfy the given conditions (For convenience, we will call it valid subsequence from now on). 
// We also list 3 invalid subsequences since their sum of the minimum element min and the maximum element max is greater than target.



class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }
};