//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//time complexity: O(n+nlogn+n) = O(nlogn)
//space complexity: O(n) (auxillary space = O(n) )

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, int>> items;
        for(int i=0; i<val.size(); i++)
        {
            items.push_back({(double)val[i]/wt[i], wt[i]});
        }
        sort(items.begin(), items.end(), [](const pair<double, int>& a, const pair<double, int>& b){
            return a.first > b.first;
        });
        int weight=0;
        double profit=0.0;
        for(int i=0; i<val.size() && weight<capacity; i++)
        {
            if(capacity-weight > items[i].second)
            {
                weight+=items[i].second;
                profit+=items[i].first * items[i].second;
            }
            else
            {
                profit+=items[i].first * (capacity-weight);
                weight=capacity;
            }
        }
        return profit;
    }
};
