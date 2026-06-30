class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty()) {
                    int city = q.front();
                    q.pop();
                    for (int j = 0; j < n; j++) {
                        if (isConnected[city][j] == 1 && !vis[j]) {
                            vis[j] = true;
                            q.push(j);

                        }
                    }
                }
            }

        }
        return count;
    }
};