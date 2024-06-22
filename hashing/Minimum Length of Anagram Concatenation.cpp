/*
You are given a string s, which is known to be a concatenation of anagrams of some string t.
Return the minimum possible length of the string t.
An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
*/


/*
esme bs hm s.size() ka divsiors nikalenge aur hr divisor k liye check krenge ki voh anagram aa rha h ya nai.
  */
class Solution {
public:
    bool isok(string s,int n){
        vector<int>f_freq(26,0);
        for(int i=0;i<n;i++) f_freq[s[i]-'a']++;
        for(int i=n;i<s.size();i+=n){
            vector<int>curr_freq(26,0);
            for(int j=i;j<i+n;j++){
                curr_freq[s[j]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(f_freq[i]!=curr_freq[i]) return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
       int n=s.size();
       for(int i=1;i<=n;i++){
        if(n%i==0 && isok(s,i)) return i;

       }
       return n;
    }
};
