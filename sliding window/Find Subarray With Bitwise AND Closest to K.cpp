//Using sliding window and Bit knowledge
//T.C : O(n*32)
//S.C : O(1)
// a & b <= a ya fir b
//aur agar piche se element htana h mtlb and jo kiy first k saath usko htana hoga and uske liye freqbits liya jo ki 
//btata h ki hmne subarray liya h usme each bit pr kitne 1 h.
class Solution {
public:

    void updateFreq(int op, int val, vector<int>& freqBits) {
        int i = 0;
        while(val > 0) {
            if((val & 1)) {
                freqBits[i] += op; //+1 in case of adding and -1 in case of removing
            }

            val /= 2;
            i++;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);

        int n = nums.size();

        int i = 0;
        int j = 0;
        int windowAnd = nums[0];
        int result = INT_MAX;

        while(j < n) {
            windowAnd = windowAnd & nums[j];
            updateFreq(1, nums[j], freqBits);

            result = min(result, abs(k - windowAnd));

            if(windowAnd > k) {
                j++;
            } else if (windowAnd == k) { //can't get a better answer than 0 (we are dealing with absolute difference)
                return 0;
            } else {
                while(i <= j && windowAnd < k) {
                    updateFreq(-1, nums[i], freqBits);
                    i++;
                    windowAnd = 0;
                    for(int b = 0; b < 32; b++){
                        if( (j-i+1) == freqBits[b]) { //jth bit of all numbers in the window (j-i+1) are set to 1
                            windowAnd = windowAnd | (1<<b);
                        }
                    }
                    result = min(result, abs(k-windowAnd));
                }
                j++;
            }
        }

        return result;
    }
};
