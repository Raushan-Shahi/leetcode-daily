// You are given a 0-indexed array nums comprising of n non-negative integers.

// In one operation, you must:

// Choose an integer i such that 1 <= i < n and nums[i] > 0.
// Decrease nums[i] by 1.
// Increase nums[i - 1] by 1.
// Return the minimum possible value of the maximum integer of nums after performing any number of operations.

//  Example 1:

// Input: nums = [3,7,1,6]
// Output: 5
// Explanation:
// One set of optimal operations is as follows:
// 1. Choose i = 1, and nums becomes [4,6,1,6].
// 2. Choose i = 3, and nums becomes [4,6,2,5].
// 3. Choose i = 1, and nums becomes [5,5,2,5].
// The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
// Therefore, we return 5.




class Solution {
public:
    typedef long long ll;

    // Function to check if a given target value is valid
    // by checking if it's possible to make all elements of nums <= target
    bool isValid(ll target, vector<int>& nums){
        if(nums[0]>target) return false; 
        ll prev=nums[0];
        for(int i=1;i<nums.size();++i){
            ll diff=target-prev; // Calculate the difference between target and previous element
            prev=nums[i]-diff; // Update prev by subtracting the difference from current element
            if(prev>target) return false; 
        }
        return true; // If all elements can be made <= target, return true
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll left=0, right=*max_element(nums.begin(),nums.end()); // Set left to 0 and right to the maximum element in nums
        while(left<right){ 
            int mid=left+(right-left)/2; 
            if(isValid(mid,nums)) right=mid; // If mid is a valid target, update right pointer
            else left=mid+1; // If mid is not a valid target, update left pointer
        }
        return right; // Return the smallest valid target value
    }
};