// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 



class Solution {
public:
    // If they form a pair of matching brackets, {} or () or [], Returns true,
    // Otherwise, it returns false.
    bool isPair(char c1, char c2) {
        return ((c1 == '{' && c2 == '}') || 
                (c1 == '(' && c2 == ')') || 
                (c1 == '[' && c2 == ']') );
    }

    bool isValid(string s) {
        int n = s.size(); 
        // is size of string is odd the return false;
        if(n % 2 == 1) return false;
        // Declaring vector for storing symbols
        vector < char > v;
        for(int i = 0 ; i < n ; i++ ) {
            if(v.size() == 0) {
                v.push_back( s[i] );
                continue;
            }
            // if both characters form a pair, remove the last symbol from vector 
            if(isPair( v[v.size() - 1], s[i] )) v.erase(v.begin() + v.size() - 1);
            else v.push_back( s[i] );
        }

        // If vector is empty, then only return true, else return false;
        return ( v.size() == 0 );
    }
};