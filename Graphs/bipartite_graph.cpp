/*We are checking if the graph is bipartite or not thorugh the method of colouring
We are trying to colour the graph with only 2 colours
if we are able to do so then the graph is bipartite else not
THIS IS ONLY THE LEETCODE VERSION
*/
class Solution {
private:
    bool ans = true;
    vector<bool> visited = vector<bool>(105, false);
    vector<bool> c = vector<bool>(105, false);
    bool dfs(int src, int pc, vector<vector<int>>& edges) {
        if (visited[src]) {
            if (pc != c[src]) {
                return true;
            } else {
                return false;
            }
        }
        visited[src] = true;
        if (pc == 0) {
            c[src] = 1;
        } else {
            c[src] = 0;
        }
        for (int x : edges[src]) {
            bool check = dfs(x, c[src], edges);
            if (!check) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i]) {
                continue;
            }
            ans = (ans and dfs(i, 0, graph));
        }
        return ans;
    }
};
