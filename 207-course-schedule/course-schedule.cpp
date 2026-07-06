class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course);
        }

        for(int i=0;i<numCourses;i++){
            for(int next:adj[i]){
                indegree[next]++;
            }
        }
        int count =0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;
            for(int next:adj[top]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return count==numCourses;
    }
};