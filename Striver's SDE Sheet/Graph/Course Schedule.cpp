// TC: O(V+E) = O(numCourses + prerequisites.size())
// SC:  O(V+E) = O(numCourses + prerequisites.size())

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(const auto& i:prerequisites)
        {
            int course=i[0];
            int preReq=i[1];
            //preReq->course
            //b->a
            //[a, b]
            adj[preReq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(const auto& i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if(count==numCourses)
        {
            return true;
        }
        return false;
    }
};
