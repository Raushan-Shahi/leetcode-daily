// A program was supposed to print an array of integers. 
// The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers
//  in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. 
// Since the answer may be very large, return it modulo 109 + 7.




class Solution {
    long long mod=1e9+7;
public:
    int c(string &s,int k,int i,vector<int>&dp){
        if(i>=s.size())return 1;
        if(s[i]=='0')return 0;
        int ans=0;
        if(dp[i]!=-1)return dp[i];
        long long d=0;
        for(int j=i;j<s.size();j++){
            d= d*10 + (s[j]-'0');
            if(d>k)break;
            ans = (ans%mod + c(s,k,j+1,dp)%mod)%mod;
        }
        dp[i]=ans;
        return ans;
    }
    int numberOfArrays(string s, int k) {
       vector<int>dp(s.size()+1,-1);
        return c(s,k,0,dp);
    }
};