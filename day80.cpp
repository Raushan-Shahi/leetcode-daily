// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k.
//  In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target




class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int N = words.size();
        int W = words[0].size();
        int T = target.size();
        vector<vector<int>> freq(W, vector<int>(26, 0));
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < N; j++) {
                int let = words[j][i] - 'a';
                freq[i][let] += 1;
            }
        }
        vector<vector<long long>> dp(T+1, vector<long long>(W+1, 0));
        for (int i = 0; i <= W; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < T; i++) {
            int tar = target[i] - 'a';
            for (int j = 0; j < W; j++) {
                int num = freq[j][tar];
                dp[i+1][j+1] = (dp[i+1][j] + (dp[i][j]*num) % 1000000007) % 1000000007;
            }
        }
        return (int)dp[T][W];
    }
};