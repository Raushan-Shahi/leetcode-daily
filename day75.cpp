// You are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.
 



class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;

        for(int i=0;i<s.size();i++){
            char cur = s[i];
            if(cur == '*'){
                stk.pop();
            }else{
                stk.push(cur);
            }
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};