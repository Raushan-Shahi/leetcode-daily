// There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has,
//  and an integer extraCandies, denoting the number of extra candies that you have.

// Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, 
// they will have the greatest number of candies among all the kids, or false otherwise.

// Note that multiple kids can have the greatest number of candies.


class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maximum = 0;
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++)
            maximum = max(candies[i], maximum);
        for (int i = 0; i < candies.size(); i++)
            candies[i] += extraCandies;

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] >= maximum)
                result.push_back(1);
            else
                result.push_back(0);
        }
        return result;
    }
};