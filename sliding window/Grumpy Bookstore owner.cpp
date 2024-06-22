/*
There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer 
array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave 
after the end of that minute.
On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, 
and is 0 otherwise.
When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.
The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.
Return the maximum number of customers that can be satisfied throughout the day.
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int s = 0;

        // Calculate the initial satisfaction without considering the grumpy periods
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                s += customers[i];
            }
        }

        int i = 0, j = 0;
        int temp = 0;
        int maxi = s;

        while (j < n) {
            // If the window size is less than 'minutes', expand the window
            if (j - i + 1 <= minutes) {
                if (grumpy[j] == 1) {
                    temp += customers[j];
                }
                j++;
            }

            // If the window size exactly matches 'minutes', calculate and update max satisfaction
            if (j - i == minutes) {
                maxi = max(s + temp, maxi);
                if (grumpy[i] == 1) {
                    temp -= customers[i];
                }
                i++;
            }
        }

        return maxi;
    }
};
