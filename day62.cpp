// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level 
// i.e. time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        int sum = satisfaction[n-1];
        int val = satisfaction[n-1];
        int max = val;
        
        for(int i = n-2; i>=0; i--)
        {
            sum += satisfaction[i];
            val += sum;         // this sum is new sum since we have added current element in prev line

            if(val > max)
                max = val;
        }
        return max < 0 ? 0 : max;   // if max less than zero, then no point in makng dishes
    }
};