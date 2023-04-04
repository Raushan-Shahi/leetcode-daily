// Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is,
//  no letter appears in a single substring more than once.

// Return the minimum number of substrings in such a partition.

// Note that each character should belong to exactly one substring in a partition.


// Example 1:

// Input: s = "abacaba"
// Output: 4
// Explanation:
// Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
// It can be shown that 4 is the minimum number of substrings needed.



class Solution {
public:
    // T:O(n), S:O(1)
    int partitionString(string s) {
        int partitions = 1;

        // A list of last seen index of each character
        vector<int> last_seen(26, -1);
        
        // Position of the new partition
        int new_partition_idx = 0;

        // Iterate the entire string and increase partitions
        for(int i = 0; i < s.size(); i++) { // O(n)
            int idx = s.at(i) - 'a';

            // If the letter is part of the current partition
            // We proceed to create a new partition
            if(last_seen[idx] >= new_partition_idx) {
                partitions++;
                new_partition_idx = i;
            }

            // Remember the last seen index of the current letter
            last_seen[idx] = i;
        }
        
        return partitions;
    }
};