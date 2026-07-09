class Solution {
private:
    vector<bool> visited = vector<bool>(100005, false);
    vector<int> distance = vector<int>(100005, -1);
    int single_cycle(int& node, vector<int>& mp) {
        unordered_map<int,bool>visited1;
        int i = 0;
        queue<int> q;
        q.push(node);
        distance[node] = i;
        visited[node] = true;
        visited1[node] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (mp[x] != -1) {
                i++;
                if (!visited[mp[x]]) {
                    distance[mp[x]] = i;
                    q.push(mp[x]);
                    visited[mp[x]] = true;
                    visited1[mp[x]] = true;
                } else {
                    if (visited1[mp[x]]) {
                        // cycle found
                        return (i - distance[mp[x]]);
                    } else {
                        // no valid cycle
                        return -1;
                    }
                }
            }
        }
        return -1;
    }
    int longestcycle(vector<int>& edges) {
        int ans = -1;
        for (int i = 0; i < edges.size(); i++) {
            ans = max(ans, single_cycle(i, edges));
        }
        return ans;
    }

public:
    int longestCycle(vector<int>& edges) { return longestcycle(edges); }
};
