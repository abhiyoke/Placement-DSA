/*
   A substring s of word is complete if:
Each character in s occurs exactly k times.
The difference between two adjacent characters is at most 2. That is, for any two adjacent characters c1 and c2 in s, the absolute difference in
their positions in the alphabet is at most 2.
Return the number of complete substrings of word.
    Leetcode Link               : https://leetcode.com/problems/count-complete-substrings/description/
*/
//Approach (Using sliding window)
//T.C : O(n*26*n) ~ O(n^2)
//S.C : O(26) We create an array of size 26 everytime. So assuming it constant
class Solution {
public:
    int solve(int start, int end, string &word, int k) {
        int result = 0;
        for(int chars = 1; chars <= 26 && chars*k <= end-start+1; chars++) {

            vector<int> count(26, 0);
            int goodChars = 0; //How many chars are of frequency k

            //Now do a sliding window
            int i = start;
            int windowLength = chars*k;
            for(int j = start; j <= end; j++) {
                char ch = word[j];

                count[ch - 'a']++;
                if(count[ch - 'a'] == k) {
                    goodChars++;
                } else if(count[ch - 'a'] == k+1) {
                    goodChars--;
                }

                if(j-i+1 > windowLength) { //Need to shift window right
                    if(count[word[i] - 'a'] == k) {
                        goodChars--;
                    } else if(count[word[i] - 'a'] == k+1) {
                        goodChars++;
                    }
                    count[word[i] - 'a']--;
                    i++;
                }

                if(goodChars == chars) {
                    result++;
                }

            }

        }

        return result;

    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.length();

        int result = 0;
        int last = 0;

        for(int i = 1; i <= n; i++) {
            if(i == n || abs(word[i] - word[i-1]) > 2) { //satisying condition 2
                result += solve(last, i-1, word, k); //condition 1
                last = i;
            }
        }

        return result;
    }
};

/*
For each possible number of unique characters chars from 1 to 26 (since there are 26 letters in the alphabet):
Ensure that chars * k is not greater than the length of the current segment.
Sliding Window Technique:
Initialize count: An array to store the frequency of each character in the current window.
Initialize goodChars: Variable to count characters that have exactly k frequency in the window.
Set i to start and windowLength to chars * k.
Iterate j from start to end:
Update the frequency of the current character in count.
If a character's frequency becomes k, increment goodChars.
If a character's frequency exceeds k, decrement goodChars.
If the window size exceeds windowLength, slide the window to the right:
Update goodChars based on the character going out of the window.
Decrement the frequency of the character going out of the window.
Increment i to slide the window.
If goodChars equals chars, increment result (indicating a complete substring).
*/
