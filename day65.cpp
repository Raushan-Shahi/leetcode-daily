// Given an array of integers nums which is sorted in ascending order, and an integer target,
//  write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.



class Solution {
public:
    int search(vector<int>& n, int t) {
        int ind = lower_bound(n.begin(),n.end() , t) - n.begin();
        if(ind < n.size() && n[ind]==t ) return ind;
        return -1;
    }
};