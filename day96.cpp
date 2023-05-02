// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).


class Solution {
public:
    int arraySign(vector<int>& a) {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) 
        {
            if(a[i] == 0) return 0;
            if(a[i] < 0) cnt++;
        }
        return cnt%2 ? -1 : 1;
    }
};