// You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

// In the ith operation (1-indexed), you will:

// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.



class Solution {
public:
    int dp[16][1 << 16];
    int help(int idx, int mask, vector<int> &nums)
    {
        // If we have picked all the elements, then return from the recursion with 0 score
        if (mask == (1 << (nums.size())))
            return 0;

        // Return already calculated state
        if(dp[idx][mask] != -1)
            return dp[idx][mask];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if current element is not picked so far, pick it
            if (((mask >> i) & 1) == 0)
            {
                // find pair for picked element...
                for (int j = 0; j < nums.size(); j++)
                {
                    // ...which is not 'i' and not picked so far
                    if (j != i and ((mask >> j) & 1) == 0)
                    {
                        // include 'i' and 'j' in our answer, recur for the next answer by enabling ith and jth bit of mask, and increment operation count also
                        ans = max(ans, idx * gcd(nums[i], nums[j]) + help(idx + 1, mask | (1 << i) | (1 << j), nums));
                    }
                }
            }
        }

        // return answer and store it into the dp
        return dp[idx][mask] = ans;
    }
    int maxScore(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        // call the function for the 1st operation with mask = 0 (means not picked any element before)
        return help(1, 0, nums);
    }
};