// this is the gfg version and we have used dfs
class Solution {
	private:
	map<int, vector<int>> mp;
	map<int, bool>visited;
	bool dfs(int node, map<int, bool>visited1) {
		if (visited[node]) {
			return false;
		}
		visited[node] = true;
		visited1[node] = true;
		for (int x:mp[node]) {
			if (!visited[x]) {
				bool smallcycle = dfs(x, visited1);
				if (smallcycle) {
					return true;
				}
			}
			else {
				if (visited1[x]) {
					return true;
				}
			}
		}
		return false;
	}
	public:
	bool isCyclic(int V, vector<vector<int>> &edges) {
		for (vector<int>v:edges) {
			mp[v[0]].push_back(v[1]);
		}
		bool ans = false;
		for (int i = 0; i<V; i++) {
			map<int, bool>visited1;
			ans = (ans or dfs(i, visited1));
			if (ans) {
				return ans;
			}
		}
		return ans;
	}
};
