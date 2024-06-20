/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets,
the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic 
force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.
  */
//T.C : O(nlogn + n*log(max_force_diff))
//S.C : O(1)

class Solution {
public:
    bool possibleToPlace(int force, vector<int>& position, int m) {

        int prev       = position[0];
        int countBalls = 1;


        for(int i = 1; i < position.size(); i++) {
            int curr = position[i];

            if(curr - prev >= force) {
                countBalls++;
                prev = curr;
            }

            if(countBalls == m)
                break;
        }

        return countBalls == m;

    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position), end(position));

        int minForce = 1;
        int maxForce = position[n-1] - position[0]; //better value (comment me batao)

        int result = 0;
        while(minForce <= maxForce) {
            int midForce = minForce + (maxForce - minForce)/2;

            if(possibleToPlace(midForce, position, m)) {
                result = midForce;
                minForce = midForce+1;
            } else {
                maxForce = midForce-1;
            }
        }

        return result;
        
    }
};
