// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary.
//  Answers within 10-5 of the actual answer will be accepted.



class Solution {
public:
    double average(vector<int>& s) {
        sort(s.begin(), s.end());
        double ans =0;
        int n = s.size();
        for(int i=1; i<n-1;i++){
            ans +=s[i];
        }
        ans = ans/(n-2);
        return ans;
    }
};