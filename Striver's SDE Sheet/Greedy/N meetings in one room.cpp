//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// time complexity : O(n + nlogn + n) = O(nlogn)
// space complexity: O(n) (O(n) for input and O(n) for auxillary space)
// auxillary space : O(n) (meetings vector)

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;
        for(int i=0; i<start.size(); i++)
        {
            meetings.push_back({start[i], end[i]});
        }
        sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.second < b.second;
        });
        int count=0, current_time=-1;
        for(const auto i : meetings)
        {
            if(i.first > current_time)
            {
                count++;
                current_time = i.second;
            }
        }
        return count;
    }
};
