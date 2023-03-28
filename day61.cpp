// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days.
//  Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.


class Solution {
public:
    int  helper(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(idx>=days.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int pass1=upper_bound(days.begin(),days.end(),days[idx]+1-1)-days.begin();
        int c1=helper(pass1,days,costs,dp)+costs[0];
        int pass7=upper_bound(days.begin(),days.end(),days[idx]+7-1)-days.begin();
        int c7=helper(pass7,days,costs,dp)+costs[1];
        int pass3=upper_bound(days.begin(),days.end(),days[idx]+30-1)-days.begin();
        int c3=helper(pass3,days,costs,dp)+costs[2];
        
        return dp[idx]=min(min(c1,c7),c3);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return helper(0,days,costs,dp);
      
    }
};