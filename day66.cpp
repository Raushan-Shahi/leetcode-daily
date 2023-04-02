// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.



class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int postfix[100001] = {0};
        for(auto potion: potions) postfix[potion]++;
        for(int i=99999; i>=0; --i) postfix[i] += postfix[i+1];

        //No need extra space at all for storing final result
        for(int i=0; i<spells.size(); ++i){
            long long val = success / (long long) spells[i];
            if(success % (long long) spells[i] != 0) val++;

            spells[i] = val <= 1e5 ? postfix[val] : 0;
        }
        return spells;
    }
};