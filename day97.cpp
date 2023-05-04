// Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

// answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
// answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
// Note that the integers in the lists may be returned in any order.




class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> ans =  {{},{}};
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        

        for(auto x : s1){
            if(s2.count(x)==0) ans[0].push_back(x);
        }
        for(auto x : s2){
            if(s1.count(x)==0) ans[1].push_back(x);
        }
		
        return ans;
    }
};
//strreak
