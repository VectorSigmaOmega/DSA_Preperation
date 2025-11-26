// TC : O(V+E) = O(numCourses + prerequisites.size())
// SC : O(V+E) = O(numCourses + prerequisites.size())

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(const auto& i:prerequisites)
        {
            int course=i[0];
            int preReq=i[1];
            //1->0
            //[0, 1]
            //[course, preReq]
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
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(const auto& i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        if (ans.size() == numCourses)
        {
            return ans;
        }
        else
        {
            return {};
        }
    }
};
