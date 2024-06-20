/*
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters
to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, 
and so on. A single word is trivially a word chain with k == 1.
Return the length of the longest possible word chain with words chosen from the given list of words
  */
class Solution {
public:
    bool compare(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1) return false;
        
        int first = 0, second = 0;
        
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                second++;
            }
            first++;
        }
        
        return second == s2.size();
    }

    int longestStrChain(vector<string> &arr) {
        int n = arr.size();
        
        // Sort the strings by their length
        sort(arr.begin(), arr.end(), [](const string &s1, const string &s2) {
            return s1.size() < s2.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;
        
        for (int i = 0; i < n; i++) {
            for (int prev_index = 0; prev_index < i; prev_index++) {
                if (compare(arr[i], arr[prev_index]) && dp[prev_index] + 1 > dp[i]) {
                    dp[i] = dp[prev_index] + 1;
                }
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }
        
        return maxi;
    }
};
