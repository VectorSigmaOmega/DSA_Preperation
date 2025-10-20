//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

//time complexity: O(nlogn + nlogn + n) = O(nlog)
//space complexity: O(n+n) = O(n)
//auxillary space = O(1)

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int count=0, arr_pointer=0, dep_pointer=0, maxPlatform=0;
        while(arr_pointer<arr.size())
        {
            if(arr[arr_pointer] <= dep[dep_pointer])
            {
                count++;
                arr_pointer++;
                maxPlatform=max(count, maxPlatform);
            }
            else
            {
                count--;
                dep_pointer++;
            }
        }
        return maxPlatform;
    }
};
