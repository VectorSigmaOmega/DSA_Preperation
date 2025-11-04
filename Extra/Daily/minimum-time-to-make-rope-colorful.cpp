// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
//Better sol;ution
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0;
        // maxCostInGroup holds the time of the balloon we are *keeping* in the current sequence
        int maxCostInGroup = neededTime[0]; 

        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                // Conflict found. We must remove one.
                // Add the *smaller* cost to our total.
                totalCost += min(maxCostInGroup, neededTime[i]);
                
                // The "survivor" for the next comparison is the one with the *larger* cost.
                maxCostInGroup = max(maxCostInGroup, neededTime[i]);
            } else {
                // No conflict. This balloon starts a new group.
                // Its cost is the new max for this new group.
                maxCostInGroup = neededTime[i];
            }
        }
        
        return totalCost;
    }
};

//My solution
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total=0;
        int maxSeq=neededTime[0];
        int conseqSum=neededTime[0];
        for(int i=1; i<colors.size(); i++)
        {
            if(colors[i]==colors[i-1])
            {
                conseqSum+=neededTime[i];
                maxSeq=max(maxSeq, neededTime[i]);
            }
            else
            {
                conseqSum-=maxSeq;
                total+=conseqSum;
                conseqSum=neededTime[i];
                maxSeq=neededTime[i];
            }
        }
        conseqSum-=maxSeq;
        total+=conseqSum;
        return total;
    }
};
