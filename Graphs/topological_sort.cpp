/*This is only the GFG version
Problem link - https://www.geeksforgeeks.org/problems/topological-sort/1
*/
class Solution {
	private:
	list<int>l;
	vector<int>ans;
	unordered_map<int, vector<int>> mp;
	vector<bool>visited=vector<bool>(10000, false);
	void initiate(vector<vector<int>> &edges) {
		for (vector<int>v:edges) {
			mp[v[0]].push_back(v[1]);
		}
		return;
	}
	void F(int node) {
		if (visited[node]) {
			return;
		}
		visited[node] = true;
		for (int x:mp[node]) {
			F(x);
		}
		l.push_front(node);
		return;
	}
	void D(int V, vector<vector<int>> &edges) {
		initiate(edges);
		for (int i = 0; i<V; i++) {
			F(i);
		}
		for (int x:l) {
			ans.push_back(x);
		}
		return;
	}
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		D(V, edges);
		return ans;
	}
};
