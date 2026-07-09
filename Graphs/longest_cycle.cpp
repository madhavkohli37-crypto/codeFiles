class Solution {
private:
    vector<bool> visited = vector<bool>(100005, false);
    vector<int> distance = vector<int>(100005, -1);
    int single_cycle(int& node, vector<int>& mp) {
        unordered_map<int,bool>visited1;//we have used aunordered map here because of 2 reasons :-
        // 1). if we use a vector then we have to initialise the size which will make the computation o(n^2) which will give TLE hence we use unordered map in which only the required
        // keys will be initialised 
        // 2). The distance is initialised outside the single_cycle function because we cannot initialise it through an unordered map because its every uninitiaslised key has a value 0 which we
        // do not want because if the cycle ends and start on the same node it will be a problem (we have to identify an uninitialised key as -1 not 0 because 0 is a possible distance).
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
